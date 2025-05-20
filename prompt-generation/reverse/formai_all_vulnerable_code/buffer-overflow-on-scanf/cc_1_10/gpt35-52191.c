//FormAI DATASET v1.0 Category: Database simulation ; Style: shape shifting
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct{
    char name[20];
    int age;
    float height;
}Person;

void addPerson(Person** people, int* size);
void removePerson(Person** people, int* size);
void displayPeople(Person* people, int size);
void searchPerson(Person* people, int size);

int main(){
    Person* people = NULL;
    int size = 0;
    int option = 0;

    do{
        printf("\n------ Database Operations ------\n");
        printf("1. Add Person\n");
        printf("2. Remove Person\n");
        printf("3. Display People\n");
        printf("4. Search Person\n");
        printf("5. Exit\n");
        printf("Enter option: ");
        scanf("%d", &option);

        switch(option){
            case 1:
                addPerson(&people, &size);
                break;
            case 2:
                removePerson(&people, &size);
                break;
            case 3:
                displayPeople(people, size);
                break;
            case 4:
                searchPerson(people, size);
                break;
            case 5:
                printf("Exiting program\n");
                break;
            default:
                printf("Invalid option\n");
                break;
        }
    } while(option != 5);

    free(people);

    return 0;
}

void addPerson(Person** people, int* size){
    *size += 1;
    *people = (Person*)realloc(*people, *size * sizeof(Person));

    if(*people == NULL){
        printf("Error reallocating memory\n");
        *size -= 1;
        return;
    }

    printf("\nEnter Person Details\n");
    printf("Name: ");
    scanf("%s", (*people)[*size-1].name);
    printf("Age: ");
    scanf("%d", &((*people)[*size-1].age));
    printf("Height: ");
    scanf("%f", &((*people)[*size-1].height));
}

void removePerson(Person** people, int* size){
    if(*size == 0){
        printf("\nDatabase is empty\n");
        return;
    }

    char name[20];
    printf("\nEnter name of person to remove: ");
    scanf("%s", name);

    for(int i = 0; i < *size; i++){
        if(strcmp(name, (*people)[i].name) == 0){
            for(int j = i; j < *size-1; j++){
                (*people)[j] = (*people)[j+1];
            }
            *size -= 1;
            *people = (Person*)realloc(*people, *size * sizeof(Person));
            printf("\n%s has been removed from the database\n", name);
            return;
        }
    }
    printf("\nPerson not found in database\n");
}

void displayPeople(Person* people, int size){
    if(size == 0){
        printf("\nDatabase is empty\n");
        return;
    }

    printf("\n---People in database---\n");
    for(int i = 0; i < size; i++){
        printf("\nName: %s\n", people[i].name);
        printf("Age: %d\n", people[i].age);
        printf("Height: %.2f\n", people[i].height);
    }
}

void searchPerson(Person* people, int size){
    if(size == 0){
        printf("\nDatabase is empty\n");
        return;
    }

    char name[20];
    printf("\nEnter name of person to search: ");
    scanf("%s", name);

    for(int i = 0; i < size; i++){
        if(strcmp(name, people[i].name) == 0){
            printf("\nPerson found!\n");
            printf("Name: %s\n", people[i].name);
            printf("Age: %d\n", people[i].age);
            printf("Height: %.2f\n", people[i].height);
            return;
        }
    }
    printf("\nPerson not found in database\n");
}