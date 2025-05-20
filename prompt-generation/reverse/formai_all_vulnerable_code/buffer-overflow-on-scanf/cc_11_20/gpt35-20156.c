//FormAI DATASET v1.0 Category: Database simulation ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int id;
    char name[20];
    int age;
} Person;

int main(){
    Person database[10];
    int numPersons = 0;

    int choice = 0;
    do{
        printf("\nWelcome to the Person Database simulation! Choose an option:\n");
        printf("1. Add person\n");
        printf("2. Remove person\n");
        printf("3. Search by ID\n");
        printf("4. Print all persons\n");
        printf("5. Quit\n");
        scanf("%d", &choice);

        switch(choice){
            case 1:{
                if(numPersons < 10){
                    Person newPerson;
                    printf("Enter person id: ");
                    scanf("%d", &newPerson.id);
                    printf("Enter person name: ");
                    scanf("%s", newPerson.name);
                    printf("Enter person age: ");
                    scanf("%d", &newPerson.age);
                    database[numPersons] = newPerson;
                    numPersons++;
                    printf("Person added successfully!\n");
                }
                else{
                    printf("Database is full. Cannot add more persons.\n");
                }
                break;
            }
            case 2:{
                int idToRemove = 0;
                printf("Enter person id to remove: ");
                scanf("%d", &idToRemove);
                int removed = 0;
                for(int i = 0; i < numPersons; i++){
                    if(database[i].id == idToRemove){
                        for(int j = i; j < numPersons - 1; j++){
                            database[j] = database[j+1];
                        }
                        numPersons--;
                        removed = 1;
                        printf("Person removed successfully!\n");
                        break;
                    }
                }
                if(!removed){
                    printf("Person not found.\n");
                }
                break;
            }
            case 3:{
                int idToSearch = 0;
                printf("Enter person id to search: ");
                scanf("%d", &idToSearch);
                int found = 0;
                for(int i = 0; i < numPersons; i++){
                    if(database[i].id == idToSearch){
                        printf("ID: %d, Name: %s, Age: %d\n", database[i].id, database[i].name, database[i].age);
                        found = 1;
                        break;
                    }
                }
                if(!found){
                    printf("Person not found.\n");
                }
                break;
            }
            case 4:{
                if(numPersons > 0){
                    for(int i = 0; i < numPersons; i++){
                        printf("ID: %d, Name: %s, Age: %d\n", database[i].id, database[i].name, database[i].age);
                    }
                }
                else{
                    printf("Database is empty.\n");
                }
                break;
            }
            case 5:{
                printf("Thank you for using the Person Database simulation!\n");
                break;
            }
            default:{
                printf("Invalid choice. Please choose again.\n");
                break;
            }
        }
    }while(choice != 5);

    return 0;
}