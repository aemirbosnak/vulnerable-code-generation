//FormAI DATASET v1.0 Category: File handling ; Style: accurate
#include<stdio.h>

typedef struct {
    char name[20];
    int age;
} Person;

// Function to add a new person to the file
void addPersonToFile(FILE *file) {
    Person newPerson;
    printf("Enter name: ");
    scanf("%s", &newPerson.name);
    printf("Enter age: ");
    scanf("%d", &newPerson.age);
    fwrite(&newPerson, sizeof(Person), 1, file);
    printf("Person successfully added to file!\n");
}

// Function to print all persons in the file
void printPersonsInFile(FILE *file) {
    Person currentPerson;
    rewind(file);
    while (fread(&currentPerson, sizeof(Person), 1, file)) {
        printf("Name: %s\tAge: %d\n", currentPerson.name, currentPerson.age);
    }
}

int main() {
    FILE *filePointer;
    char fileName[20];
    int userInput;
    
    printf("Enter file name: ");
    scanf("%s", fileName);
    filePointer = fopen(fileName, "ab+"); // Open file in append and binary mode
    
    if (filePointer == NULL) {
        printf("Error opening file. Exiting program.");
        return 1;
    }
    
    printf("\n===== FILE OPTIONS =====");
    printf("\n1. Add new person to file");
    printf("\n2. Print all persons in file");
    printf("\n3. Exit program");
    printf("\n========================\n");
    
    while (1) {
        printf("\nEnter option (1-3): ");
        scanf("%d", &userInput);
        switch(userInput) {
            case 1:
                addPersonToFile(filePointer);
                break;
            case 2:
                printPersonsInFile(filePointer);
                break;
            case 3:
                printf("Exiting program. Have a nice day!");
                fclose(filePointer);
                return 0;
            default:
                printf("Invalid input. Please try again.");
        }
    }
    
    fclose(filePointer);
    return 0;
}