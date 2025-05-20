//FormAI DATASET v1.0 Category: Phone Book ; Style: mathematical
#include<stdio.h>
#include<string.h>
#define MAX 1000

//Function to insert a contact
void insert(char list[MAX][2][50], int *size){
    //temporarily store input values
    char name[50], number[50];
    //prompt user for name and number
    printf("Enter the name: ");
    scanf("%s", name);
    printf("Enter the phone number: ");
    scanf("%s", number);
    //check if contact already exists
    for(int i=0; i<*size; i++){
        if(strcmp(list[i][0], name) == 0){
            printf("Contact already exists!\n");
            return;
        }
    }
    //add contact to list
    strcpy(list[*size][0], name);
    strcpy(list[*size][1], number);
    (*size)++;
    printf("Contact added successfully!\n");
}

//Function to search for a contact and display its information
void search(char list[MAX][2][50], int size){
    //temporarily store input value
    char name[50];
    //prompt user for name
    printf("Enter the name: ");
    scanf("%s", name);
    //search for contact in list
    for(int i=0; i<size; i++){
        if(strcmp(list[i][0], name) == 0){
            printf("Name: %s\n", list[i][0]);
            printf("Phone number: %s\n", list[i][1]);
            return;
        }
    }
    printf("Contact not found!\n");
}

//Function to display all contacts in the phone book
void display(char list[MAX][2][50], int size){
    //display all contacts in list
    for(int i=0; i<size; i++){
        printf("Name: %s\n", list[i][0]);
        printf("Phone number: %s\n", list[i][1]);
        printf("\n");
    }
}

//Function to delete a contact from the phone book
void delete(char list[MAX][2][50], int *size){
    //temporarily store input value
    char name[50];
    //prompt user for name
    printf("Enter the name: ");
    scanf("%s", name);
    //search for contact in list
    for(int i=0; i<*size; i++){
        if(strcmp(list[i][0], name) == 0){
            //shift all contacts after the deleted contact up one index
            for(int j=i; j<(*size)-1; j++){
                strcpy(list[j][0], list[j+1][0]);
                strcpy(list[j][1], list[j+1][1]);
            }
            (*size)--;
            printf("Contact deleted successfully!\n");
            return;
        }
    }
    printf("Contact not found!\n");
}

int main(){
    //initialize variables
    char list[MAX][2][50];
    int size = 0, choice;
    //display menu options and prompt user for choice
    while(1){
        printf("\n--------------------------\n");
        printf("Phone Book Menu\n");
        printf("--------------------------\n");
        printf("1. Insert new contact\n");
        printf("2. Search for a contact\n");
        printf("3. Display all contacts\n");
        printf("4. Delete a contact\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        //call appropriate function based on user choice
        switch(choice){
            case 1:
                insert(list, &size);
                break;
            case 2:
                search(list, size);
                break;
            case 3:
                display(list, size);
                break;
            case 4:
                delete(list, &size);
                break;
            case 5:
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}