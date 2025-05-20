//FormAI DATASET v1.0 Category: Database Indexing System ; Style: peaceful
// C Program to Implement Indexing System for Database

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Structure to store database values
struct Database {
    int id_num;
    char name[20];
    char email[50];
    char address[100];
};

// Structure to store index values
struct Index{
    int id_num;
    int offset;
};

// Function to compare two index structures based on id_num
int comp_index(const void *a, const void *b){
    struct Index *p = (struct Index *)a;
    struct Index *q = (struct Index *)b;
    return p->id_num - q->id_num;
}

// Main function
int main(){
    FILE *fp, *fp_idx;
    int ch, id;
    char file_name[20] = "database.txt";
    char idx_file_name[20] = "index.txt";
    struct Database db;
    struct Index idx[100], temp;
    int i = 0, j, num_of_records = 0, flag = 0, choice;
    
    // Open database file and index file in append mode
    fp = fopen(file_name, "a+");
    fp_idx = fopen(idx_file_name, "a+");
    
    rewind(fp_idx);
    while(fread(&temp, sizeof(struct Index), 1, fp_idx)){
        idx[num_of_records] = temp;
        num_of_records++;
    }
    
    // Menu Driven Program
    while(1){
        // User Menu
        printf("\n\n1. Add Record\n");
        printf("2. Delete Record\n");
        printf("3. Search Record\n");
        printf("4. Display All Records\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice){
            case 1: // Adding Record
                printf("Enter ID: ");
                scanf("%d", &db.id_num);
                
                // Checking whether id already exists
                for(j=0;j<num_of_records;j++){
                    if(idx[j].id_num == db.id_num){
                        printf("Record with this ID already exists.\n");
                        flag = 1;
                        break;
                    }
                }
                
                if(flag == 1){
                    flag = 0;
                    break;
                }
                
                printf("Enter Name: ");
                scanf("%s", db.name);
                printf("Enter Email: ");
                scanf("%s", db.email);
                printf("Enter Address: ");
                scanf("%s", db.address);
                
                // Adding record in database file
                fseek(fp, 0, SEEK_END);
                fwrite(&db, sizeof(struct Database), 1, fp);
                
                // Adding index in index file
                idx[num_of_records].id_num = db.id_num;
                idx[num_of_records].offset = ftell(fp) - sizeof(struct Database);
                num_of_records++;
                fwrite(&idx[num_of_records-1], sizeof(struct Index), 1, fp_idx);
                
                printf("Record Added Successfully.\n");
                break;
            
            case 2: // Deleting Record
                printf("Enter ID of record to be deleted: ");
                scanf("%d", &id);
                flag = 0;
                
                // Deleting record with given id
                rewind(fp_idx);
                for(i=0;i<num_of_records;i++){
                    fread(&temp, sizeof(struct Index), 1, fp_idx);
                    if(temp.id_num == id){
                        flag = 1;
                        break;
                    }
                }
                
                if(flag == 0){
                    printf("Record with given ID not found in database.\n");
                    break;
                }
                
                // Updating indices
                for(j=i;j<num_of_records-1;j++){
                    idx[j] = idx[j+1];
                }
                num_of_records--;
                
                //Writing updated indices in index file
                fclose(fp_idx);
                fp_idx = fopen(idx_file_name, "w");
                for(i=0;i<num_of_records;i++){
                    fwrite(&idx[i], sizeof(struct Index), 1, fp_idx);
                }
                fclose(fp_idx);
                
                // Updating database file
                fp = freopen(file_name, "w+", fp);
                if(num_of_records == 0){
                    break;
                }
                
                fseek(fp, idx[0].offset, SEEK_SET);
                for(i=0;i<num_of_records;i++){
                    if(i == num_of_records-1){
                        fp = freopen(file_name, "w+", fp);
                        ftruncate(fileno(fp), idx[i].offset);
                        break;
                    }
                    fwrite(&db, sizeof(struct Database), 1, fp);
                    fseek(fp, idx[i+1].offset, SEEK_SET);
                    fread(&db, sizeof(struct Database), 1, fp);
                }
                printf("Record Deleted Successfully.\n");
                break;
            
                
            case 3: // Searching Record
                printf("Enter ID of record to search: ");
                scanf("%d", &id);
                flag = 0;
                
                // Searching record by given id
                rewind(fp_idx);
                for(i=0;i<num_of_records;i++){
                    fread(&temp, sizeof(struct Index), 1, fp_idx);
                    if(temp.id_num == id){
                        flag = 1;
                        fseek(fp, temp.offset, SEEK_SET);
                        fread(&db, sizeof(struct Database), 1, fp);
                        printf("\nID: %d\nName: %s\nEmail: %s\nAddress: %s", db.id_num, db.name, db.email, db.address);
                        break;
                    }
                }
                if(flag == 0){
                    printf("Record with given ID not found.\n");
                }
                break;
            
            case 4: // Displaying All Records
                rewind(fp);
                printf("\n\nID\tNAME\tEMAIL\t\tADDRESS\n\n");
                while(fread(&db, sizeof(struct Database), 1, fp)){
                    printf("%d\t%s\t%s\t%s\n", db.id_num, db.name, db.email, db.address);
                }
                break;
            
            case 5: // Exiting Program
                fclose(fp);
                fclose(fp_idx);
                exit(0);
                
            default:
                printf("Invalid choice.\n");
                break;
        }
    }
    return 0;
}