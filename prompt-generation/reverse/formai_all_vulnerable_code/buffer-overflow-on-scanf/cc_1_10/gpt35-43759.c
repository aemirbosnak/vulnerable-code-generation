//FormAI DATASET v1.0 Category: Database simulation ; Style: shocked
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct{
    int id;
    char name[50];
    int age;
}person;

void insert(person *database, int *size){
    printf("Enter the person's details:\n");
    database = realloc(database, (*size + 1) * sizeof(person));
    printf("ID: ");
    scanf("%d", &(database[*size].id));
    printf("Name: ");
    scanf("%s", database[*size].name);
    printf("Age: ");
    scanf("%d", &(database[*size].age));
    (*size)++;
}

void display(person *database, int size){
    printf("ID \t NAME \t\t AGE\n");
    printf("================================\n");
    for(int i = 0; i < size; i++){
        printf("%d \t %s \t\t %d\n", database[i].id, database[i].name, database[i].age);
    }
}

int main(){
    int choice, size = 0;
    person *database = NULL;
    while(1){
        printf("1-INSERT\n2-DISPLAY\n3-EXIT\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                insert(database, &size);
                break;
            case 2:
                display(database, size);
                break;
            case 3:
                printf("Goodbye!\n");
                free(database);
                return 0;
            default:
                printf("Error: Invalid choice!\n");
        }
    }
    return 0;
}