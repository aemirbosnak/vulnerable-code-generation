//FormAI DATASET v1.0 Category: Database simulation ; Style: complex
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct employee{
    char name[30],department[30],id[10],age[5];
};

void add_employee();
void remove_employee();
void search_employee();
void display_database();

int main(){
    int choice;
    printf("\nWelcome to Employee Database Simulation\n\n");

    while(1){
        printf("\n\nWhat would you like to do?\n");
        printf("1) Add an employee\n");
        printf("2) Remove an employee\n");
        printf("3) Search for an employee\n");
        printf("4) Display database\n");
        printf("Enter choice (1-4): ");
        scanf("%d",&choice);

        switch(choice){
        case 1:
            add_employee();
            break;
        case 2:
            remove_employee();
            break;
        case 3:
            search_employee();
            break;
        case 4:
            display_database();
            break;
        default:
            printf("Invalid choice. Try again.\n");
            break;
        }
    }

    return 0;
}

void add_employee(){
    struct employee e;
    FILE *fp;
    fp=fopen("database.bin","ab");

    printf("\nEnter details for the new employee:\n");
    printf("Name: ");
    scanf("%s",e.name);
    printf("Department: ");
    scanf("%s",e.department);
    printf("ID: ");
    scanf("%s",e.id);
    printf("Age: ");
    scanf("%s",e.age);

    fwrite(&e,sizeof(e),1,fp);
    fclose(fp);
}

void remove_employee(){
    struct employee e,temp;
    FILE *fp,*fptemp;
    int found=0;

    fp=fopen("database.bin","rb");
    fptemp=fopen("temp.bin","wb");

    printf("\nEnter ID of employee to be deleted: ");
    char id[10];
    scanf("%s",id);

    while(fread(&e,sizeof(e),1,fp)){
        if(strcmp(e.id,id)==0){
            found=1;
            continue;
        }
        fwrite(&e,sizeof(e),1,fptemp);
    }

    fclose(fp);
    fclose(fptemp);

    if(found==0){
        printf("\nNo employee found with given ID.\n");
    }
    else{
        remove("database.bin");
        rename("temp.bin","database.bin");
        printf("\nEmployee with ID %s removed.\n",id);
    }
}

void search_employee(){
    struct employee e;
    FILE *fp;
    int found=0;

    fp=fopen("database.bin","rb");

    printf("\nEnter ID of employee to be searched: ");
    char id[10];
    scanf("%s",id);

    while(fread(&e,sizeof(e),1,fp)){
        if(strcmp(e.id,id)==0){
            printf("\nEmployee Found\n");
            printf("Name: %s\n",e.name);
            printf("Department: %s\n",e.department);
            printf("ID: %s\n",e.id);
            printf("Age: %s\n",e.age);
            found=1;
            break;
        }
    }

    fclose(fp);

    if(found==0){
        printf("\nNo employee found with given ID.\n");
    }
}

void display_database(){
    struct employee e;
    FILE *fp;

    fp=fopen("database.bin","rb");

    printf("\nCurrent Employee Database:\n\n");

    printf("Name\t\tDepartment\tID\tAge\n\n");

    while(fread(&e,sizeof(e),1,fp)){
        printf("%s\t\t%s\t\t%s\t%s\n",e.name,e.department,e.id,e.age);
    }

    fclose(fp);
}