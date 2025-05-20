//FormAI DATASET v1.0 Category: Mailing list manager ; Style: Ada Lovelace
//The following program is a Mailing list manager example program 
//in a Ada Lovelace style written in C language.

#include<stdio.h>
#include<string.h>

//Structure of each person's data
typedef struct {
    char name[50];
    char email[50];
} Person;

//Function declaration
void addToList(Person list[], int* counter);
void displayList(Person list[], int counter);
void searchList(Person list[], int counter);

//Main function
int main(){
    
    Person personList[100];  //Array to store the person's data
    int totalPersons=0;      //Total number of person in the list
    
    //Loop to give user different options
    while(1){
        int choice;
        printf("\n--------Mailing List Manager--------\n");
        printf("\nChoose an option:\n1. Add a Person\n2. Display List\n3. Search Person\n4. Exit\n");
        scanf("%d", &choice);
        
        //Switchcases to perform different options
        switch(choice){
            case 1:
                addToList(personList, &totalPersons);
                break;
            case 2:
                displayList(personList, totalPersons);
                break;
            case 3:
                searchList(personList, totalPersons);
                break;
            case 4:
                printf("\nExiting Program...\n");
                exit(0);
            default:
                printf("\nInvalid Option! Please Try Again.\n");
                break;
        }
    }
    return 0;
}

//Function to add person data to the list
void addToList(Person list[], int* counter){
    printf("\nAdding Person:\n");
    printf("Name: ");
    scanf("%s", list[*counter].name);
    printf("Email: ");
    scanf("%s", list[*counter].email);
    (*counter)++;
    printf("\nPerson Added Successfully.\n");
}

//Function to display all the persons in the list
void displayList(Person list[], int counter){
    if(counter==0){
        printf("\nNo Data Available!\n");
        return;
    }

    printf("\n-------List of Persons-------\n");
    printf("Total Persons: %d\n", counter);
    for(int i=0; i<counter; i++){
        printf("%d. Name: %s Email: %s\n", i+1, list[i].name, list[i].email);
    }
    printf("\n");
}

//Function to search for a person in the list
void searchList(Person list[], int counter){
    if(counter==0){
        printf("\nNo Data Available!\n");
        return;
    }
    
    char searchName[50];
    printf("\nEnter the Name to search for: ");
    scanf("%s", searchName);
    
    for(int i=0; i<counter; i++){
        if(strcmp(list[i].name, searchName)==0){
            printf("\nPerson Found!\nName: %s Email: %s\n", list[i].name, list[i].email);
            return;
        }
    }
    printf("\nPerson Not Found!\n");
}