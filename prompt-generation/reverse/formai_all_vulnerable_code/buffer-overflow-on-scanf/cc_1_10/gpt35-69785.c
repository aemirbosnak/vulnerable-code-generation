//FormAI DATASET v1.0 Category: File handling ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// function to read data from file
void readFromFile() {
    FILE *filePointer;
    char ch;
    
    // open the file in read mode
    filePointer = fopen("sample.txt", "r");
    
    // check if file is opened successfully or not
    if (filePointer == NULL) {
        printf("File could not be opened!");
        return;
    }
    
    // read the contents of file
    printf("Contents of sample.txt file are:\n");
    while ((ch = fgetc(filePointer)) != EOF) {
        printf("%c", ch);
    }
    
    // close the file
    fclose(filePointer);
}

// function to write data to file
void writeToFile() {
    FILE *filePointer;
    char name[30];
    int age;
    float salary;
    
    // open the file in write mode
    filePointer = fopen("employee.txt", "w");
    
    // check if file is opened successfully or not
    if (filePointer == NULL) {
        printf("File could not be opened!");
        return;
    }
    
    // get employee details from user
    printf("Enter employee name: ");
    scanf("%s", name);
    printf("Enter employee age: ");
    scanf("%d", &age);
    printf("Enter employee salary: ");
    scanf("%f", &salary);
    
    // write employee details to file
    fprintf(filePointer, "Name: %s\nAge: %d\nSalary: %.2f", name, age, salary);
    
    // close the file
    fclose(filePointer);
}

int main() {
    int choice;
    
    // display menu for file handling operations
    while(1) {
        printf("\n======= FILE HANDLING MENU =======\n");
        printf("1. Read data from file\n");
        printf("2. Write data to file\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            // read data from file
            case 1: readFromFile();
                    break;
                    
            // write data to file
            case 2: writeToFile();
                    printf("Employee details written to employee.txt file!");
                    break;
                    
            // exit the program
            case 3: exit(0);
            
            // default case - invalid choice
            default: printf("Invalid choice. Please try again!");
        }
    }
    
    return 0;
}