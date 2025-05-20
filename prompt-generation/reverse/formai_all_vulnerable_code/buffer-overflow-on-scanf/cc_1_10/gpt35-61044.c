//FormAI DATASET v1.0 Category: Phone Book ; Style: active
#include <stdio.h>
#include <string.h>

struct PhoneBook{
    char name[50];
    long int number;
};

typedef struct PhoneBook pb;

pb phoneBookList[100];
int count = 0;

void addEntry(){
    printf("Enter name: ");
    scanf("%s", phoneBookList[count].name);
    printf("Enter phone number: ");
    scanf("%ld", &phoneBookList[count].number);
    count++;
    printf("Entry added successfully!\n");
}

void showEntries(){
    if(count == 0){
        printf("No entries found!\n");
        return;
    }
    
    printf("List of entries:\n");
    for(int i=0; i<count; i++){
        printf("Name: %s\nPhone number: %ld\n", phoneBookList[i].name, phoneBookList[i].number);
    }
}

void searchEntry(){
    if(count == 0){
        printf("No entries found!\n");
        return;
    }
    char name[50];
    printf("Enter name to search: ");
    scanf("%s", name);
    int found = 0;
    for(int i=0; i<count; i++){
        if(strcmp(phoneBookList[i].name, name) == 0){
            printf("Name: %s\nPhone number: %ld\n", phoneBookList[i].name, phoneBookList[i].number);
            found = 1;
        }
    }
    if(!found){
        printf("No matching entry found!\n");
    }
}

void updateEntry(){
    if(count == 0){
        printf("No entries found!\n");
        return;
    }
    char name[50];
    printf("Enter name to update: ");
    scanf("%s", name);
    int found = 0;
    for(int i=0; i<count; i++){
        if(strcmp(phoneBookList[i].name, name) == 0){
            printf("Enter updated phone number: ");
            scanf("%ld", &phoneBookList[i].number);
            printf("Entry updated successfully!\n");
            found = 1;
        }
    }
    if(!found){
        printf("No matching entry found!\n");
    }
}

void deleteEntry(){
    if(count == 0){
        printf("No entries found!\n");
        return;
    }
    char name[50];
    printf("Enter name to delete: ");
    scanf("%s", name);
    int found = 0;
    for(int i=0; i<count; i++){
        if(strcmp(phoneBookList[i].name, name) == 0){
            for(int j=i; j<count; j++){
                strcpy(phoneBookList[j].name, phoneBookList[j+1].name);
                phoneBookList[j].number = phoneBookList[j+1].number;
            }
            count--;
            printf("Entry deleted successfully!\n");
            found = 1;
        }
    }
    if(!found){
        printf("No matching entry found!\n");
    }
}

int main(){
    int choice;
    do{
        printf("\n********************\n");
        printf("1. Add an entry\n");
        printf("2. Show all entries\n");
        printf("3. Search for an entry\n");
        printf("4. Update an entry\n");
        printf("5. Delete an entry\n");
        printf("6. Exit\n");
        printf("********************\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice){
            case 1:
                addEntry();
                break;
            case 2:
                showEntries();
                break;
            case 3:
                searchEntry();
                break;
            case 4:
                updateEntry();
                break;
            case 5:
                deleteEntry();
                break;
            case 6:
                printf("Thank you for using PhoneBook!\n");
                break;
            default:
                printf("Invalid choice, please try again!\n");
                break;
        }
    } while(choice != 6);
    
    return 0;
}