//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: safe
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct medicine{
    int id;
    char name[30];
    float price;
    int quantity;
}med;

void add_medicine(){
    FILE *fp;
    fp=fopen("medicine_data.txt","ab");

    printf("\n\tEnter medicine details:\n");
    printf("\t\tID: ");
    scanf("%d",&med.id);
    printf("\t\tName: ");
    scanf("%s",med.name);
    printf("\t\tPrice: ");
    scanf("%f",&med.price);
    printf("\t\tQuantity: ");
    scanf("%d",&med.quantity);

    fwrite(&med,sizeof(med),1,fp);//writing data to the file

    printf("\n\tThe medicine record has been added successfully!");
    fclose(fp);//closing the file
}

void search_medicine(){
    FILE *fp;
    int id,found=0;

    fp=fopen("medicine_data.txt","rb");
    printf("\n\tEnter medicine ID to search: ");
    scanf("%d",&id);

    while(fread(&med,sizeof(med),1,fp)==1){
        if(med.id==id){
            printf("\n\tThe medicine record has been found!\n");
            printf("\tID: %d\n",med.id);
            printf("\tName: %s\n",med.name);
            printf("\tPrice: %.2f\n",med.price);
            printf("\tQuantity: %d\n",med.quantity);
            found=1;
            break;
        }
    }
    if(!found){
        printf("\n\tThe medicine record not found!");
    }
    fclose(fp);
}

void edit_medicine(){
    FILE *fp;
    int id,found=0;

    fp=fopen("medicine_data.txt","rb+");//opening the file in update mode
    printf("\n\tEnter medicine ID to edit: ");
    scanf("%d",&id);

    while(fread(&med,sizeof(med),1,fp)==1){
        if(med.id==id){
            printf("\n\tThe medicine record has been found!");
            printf("\n\tEnter new details of medicine:\n");
            printf("\t\tID: ");
            scanf("%d",&med.id);
            printf("\t\tName: ");
            scanf("%s",med.name);
            printf("\t\tPrice: ");
            scanf("%f",&med.price);
            printf("\t\tQuantity: ");
            scanf("%d",&med.quantity);

            fseek(fp,-sizeof(med),SEEK_CUR);//setting the file position pointer to the start of the record
            fwrite(&med,sizeof(med),1,fp);//writing the updated record to the file
            printf("\n\tThe medicine record has been updated successfully!");
            found=1;
            break;
        }
    }
    if(!found){
        printf("\n\tThe medicine record could not be updated!");
    }
    fclose(fp);
}

void delete_medicine(){
    FILE *fp,*temp;
    int id,found=0;

    fp=fopen("medicine_data.txt","rb");//opening the file in reading mode
    temp=fopen("temp.txt","wb");//creating a temporary file in writing mode

    printf("\n\tEnter medicine ID to delete: ");
    scanf("%d",&id);

    while(fread(&med,sizeof(med),1,fp)==1){
        if(med.id==id){
            printf("\n\tThe medicine record has been found!");
            printf("\n\tThe medicine record has been deleted successfully!");
            found=1;
        }
        else{
            fwrite(&med,sizeof(med),1,temp);
        }
    }
    if(!found){
        printf("\n\tThe medicine record could not be found!");
    }
    fclose(fp);
    fclose(temp);
    remove("medicine_data.txt");//removing the original file
    rename("temp.txt","medicine_data.txt");//renaming the temporary file to original file name
}

void display_medicine(){
    FILE *fp;

    fp=fopen("medicine_data.txt","rb");
    printf("\n\tMedicines in stock are listed below:\n\n");
    while(fread(&med,sizeof(med),1,fp)==1){
        printf("\tID: %d\n",med.id);
        printf("\tName: %s\n",med.name);
        printf("\tPrice: %.2f\n",med.price);
        printf("\tQuantity: %d\n",med.quantity);
        printf("\n");
    }
    fclose(fp);
}

int main(){
    int choice;
    printf("\n\t\tWELCOME TO MEDICAL STORE MANAGEMENT SYSTEM");
    while(1){
        printf("\n\n\tMAIN MENU\n");
        printf("\t1. Add Medicine");
        printf("\n\t2. Search Medicine");
        printf("\n\t3. Edit Medicine");
        printf("\n\t4. Delete Medicine");
        printf("\n\t5. Display All Medicines");
        printf("\n\t6. Exit");
        printf("\n\n\tEnter your choice: ");
        scanf("%d",&choice);

        switch(choice){
            case 1:
                add_medicine();
                break;

            case 2:
                search_medicine();
                break;

            case 3:
                edit_medicine();
                break;

            case 4:
                delete_medicine();
                break;

            case 5:
                display_medicine();
                break;

            case 6:
                printf("\n\tThank you for using the software!\n");
                exit(0);//function to terminate the program
                break;

            default:
                printf("\n\tInvalid choice!");
        }
    }
    return 0;
}