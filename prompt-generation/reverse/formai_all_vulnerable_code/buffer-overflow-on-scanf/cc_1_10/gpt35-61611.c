//FormAI DATASET v1.0 Category: Database simulation ; Style: surprised
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Student{
    char name[30];
    int id;
    float cgpa;
};

void clear(){
    #ifdef _WIN32
    system("cls");
    #else
    system("clear");
    #endif
}

void display(struct Student stu[], int size){
    clear();
    printf("List of Students:\n");
    printf("_____________________________\n");
    for(int i=0;i<size;i++){
        printf("%s\nID: %d\nCGPA: %.2f\n", stu[i].name, stu[i].id, stu[i].cgpa);
        printf("_____________________________\n");
    }
}

void insert(struct Student *stu, int size){
    clear();
    printf("Enter the details of the Student to be added: \n");
    printf("Name: ");
    fflush(stdin);
    scanf("%s",stu[size].name);
    printf("ID: ");
    scanf("%d",&stu[size].id);
    printf("CGPA: ");
    scanf("%f",&stu[size].cgpa);
    printf("The Student has been added to the list!\n");
}

void search(struct Student stu[], int size){
    clear();
    int id_search, flag = 0;
    printf("Enter the ID of the Student to search: ");
    scanf("%d",&id_search);
    for(int i=0;i<size;i++){
        if(id_search == stu[i].id){
            flag=1;
            printf("Student Found:\n");
            printf("_____________________________\n");
            printf("%s\nID: %d\nCGPA: %.2f\n", stu[i].name, stu[i].id, stu[i].cgpa);
            printf("_____________________________\n");
        }
    }
    if(flag==0){
        printf("No student found with the given ID!\n");
    }
}

void modify(struct Student stu[], int size){
    clear();
    int id_mod, flag = 0, choice;
    printf("Enter the ID of the Student to modify: ");
    scanf("%d",&id_mod);
    for(int i=0;i<size;i++){
        if(id_mod == stu[i].id){
            flag=1;
            printf("Student Found:\n");
            printf("%s\nID: %d\nCGPA: %.2f\n\n", stu[i].name, stu[i].id, stu[i].cgpa);
            printf("What do you want to modify?\n");
            printf("1. Name\n2. ID\n3. CGPA\nEnter your choice: ");
            scanf("%d",&choice);
            switch(choice){
                case 1:
                    printf("Enter the new Name: ");
                    scanf("%s",stu[i].name);
                    printf("The Name has been modified!\n");
                    break;
                case 2:
                    printf("Enter the new ID: ");
                    scanf("%d",&stu[i].id);
                    printf("The ID has been modified!\n");
                    break;
                case 3:
                    printf("Enter the new CGPA: ");
                    scanf("%f",&stu[i].cgpa);
                    printf("The CGPA has been modified!\n");
                    break;
                default:
                    printf("Invalid Choice selected!\n");
                    break;
            }
        }
    }
    if(flag==0){
        printf("No student found with the given ID!\n");
    }
}

void delete(struct Student *stu, int *size){
    clear();
    int id_del, flag = 0;
    printf("Enter the ID of the Student to delete: ");
    scanf("%d",&id_del);
    for(int i=0;i<*size;i++){
        if(id_del == stu[i].id){
            flag=1;
            for(int j=i;j<*size;j++){
                strcpy(stu[j].name,stu[j+1].name);
                stu[j].id = stu[j+1].id;
                stu[j].cgpa = stu[j+1].cgpa;
            }
            *size -= 1;
            printf("The Student has been deleted!\n");
            break;
        }
    }
    if(flag==0){
        printf("No student found with the given ID!\n");
    }
}

int main(){
    struct Student stu[100];
    int size=0, choice;
    while(1){
        clear();
        printf("*** Student Database Simulation ***\n");
        printf("1. Display\n2. Insert a Student\n3. Search a Student\n4. Modify a Student's record\n5. Delete a Student's record\n6. Exit\nEnter your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                if(size == 0){
                    printf("No Students found in the database!\n");
                }
                else{
                    display(stu, size);
                }
                break;
            case 2:
                insert(stu, size);
                size += 1;
                break;
            case 3:
                search(stu, size);
                break;
            case 4:
                modify(stu, size);
                break;
            case 5:
                delete(stu, &size);
                break;
            case 6:
                printf("Exiting...");
                exit(0);
                break;
            default:
                printf("Invalid Choice selected!\n");
        }
        getchar();
        printf("Press Enter to continue...");
        getchar();
    }
    return 0;
}