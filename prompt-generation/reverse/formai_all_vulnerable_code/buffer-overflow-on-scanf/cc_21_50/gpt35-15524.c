//FormAI DATASET v1.0 Category: Database simulation ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store student information
typedef struct {
    int id;
    char name[20];
    char major[20];
} Student;

int main() {
    // Variables
    int choice, n;
    Student *students = NULL;
    FILE *fp = NULL;
    char filename[20];
    
    // Menu
    printf("C DATABASE SIMULATION\n");
    printf("1. Create database\n");
    printf("2. Add student record\n");
    printf("3. Display student record\n");
    printf("4. Modify student record\n");
    printf("5. Delete student record\n");
    printf("6. Exit\n");
    
    // Choice input
    printf("Enter your choice: ");
    scanf("%d", &choice);
    
    while (choice != 6) {
        switch(choice) {
            case 1:
                // Create database
                printf("Enter number of students: ");
                scanf("%d", &n);
                students = (Student*)malloc(n*sizeof(Student));
                
                // Fill with default values
                for (int i = 0; i < n; i++) {
                    students[i].id = i + 1;
                    strcpy(students[i].name, "None");
                    strcpy(students[i].major, "Undeclared");
                }
                
                printf("Database created.\n");
                
                break;
            case 2:
                // Add student record
                if (students == NULL) {
                    printf("Database does not exist.\n");
                } else {
                    int id;
                    printf("Enter ID number: ");
                    scanf("%d", &id);
                    
                    // Check if ID already exists
                    int exists = 0;
                    for (int i = 0; i < n; i++) {
                        if (students[i].id == id) {
                            exists = 1;
                            break;
                        }
                    }
                    
                    if (exists) {
                        printf("ID already exists.\n");
                    } else {
                        char name[20], major[20];
                        printf("Enter name: ");
                        scanf("%s", name);
                        printf("Enter major: ");
                        scanf("%s", major);
                        
                        // Insert record
                        for (int i = 0; i < n; i++) {
                            if (students[i].id == 0) {
                                students[i].id = id;
                                strcpy(students[i].name, name);
                                strcpy(students[i].major, major);
                                break;
                            }
                        }
                        
                        printf("Student record added.\n");
                    }
                }
                
                break;
            case 3:
                // Display student record
                if (students == NULL) {
                    printf("Database does not exist.\n");
                } else {
                    int id;
                    printf("Enter ID number: ");
                    scanf("%d", &id);
                    
                    // Search for ID
                    int index = -1;
                    for (int i = 0; i < n; i++) {
                        if (students[i].id == id) {
                            index = i;
                            break;
                        }
                    }
                    
                    if (index == -1) {
                        printf("ID not found.\n");
                    } else {
                        printf("ID: %d\nName: %s\nMajor: %s\n", students[index].id, students[index].name, students[index].major);
                    }
                }
                
                break;
            case 4:
                // Modify student record
                if (students == NULL) {
                    printf("Database does not exist.\n");
                } else {
                    int id;
                    printf("Enter ID number: ");
                    scanf("%d", &id);
                    
                    // Search for ID
                    int index = -1;
                    for (int i = 0; i < n; i++) {
                        if (students[i].id == id) {
                            index = i;
                            break;
                        }
                    }
                    
                    if (index == -1) {
                        printf("ID not found.\n");
                    } else {
                        char name[20], major[20];
                        printf("Enter name: ");
                        scanf("%s", name);
                        printf("Enter major: ");
                        scanf("%s", major);
                        
                        // Modify record
                        strcpy(students[index].name, name);
                        strcpy(students[index].major, major);
                        
                        printf("Student record modified.\n");
                    }
                }
                
                break;
            case 5:
                // Delete student record
                if (students == NULL) {
                    printf("Database does not exist.\n");
                } else {
                    int id;
                    printf("Enter ID number: ");
                    scanf("%d", &id);
                    
                    // Search for ID
                    int index = -1;
                    for (int i = 0; i < n; i++) {
                        if (students[i].id == id) {
                            index = i;
                            break;
                        }
                    }
                    
                    if (index == -1) {
                        printf("ID not found.\n");
                    } else {
                        // Delete record
                        students[index].id = 0;
                        strcpy(students[index].name, "None");
                        strcpy(students[index].major, "Undeclared");
                        
                        printf("Student record deleted.\n");
                    }
                }
                
                break;
            default:
                printf("Invalid choice.\n");
        }
        
        // Menu
        printf("\nC DATABASE SIMULATION\n");
        printf("1. Create database\n");
        printf("2. Add student record\n");
        printf("3. Display student record\n");
        printf("4. Modify student record\n");
        printf("5. Delete student record\n");
        printf("6. Exit\n");
        
        // Choice input
        printf("Enter your choice: ");
        scanf("%d", &choice);
    }
    
    // Save to file
    printf("Enter filename to save database: ");
    scanf("%s", filename);
    
    fp = fopen(filename, "wb");

    if (fp == NULL)
    {
        printf("Error: cannot open file.\n");
        exit(1);
    }
 
    fwrite(&n, sizeof(int), 1, fp);
    fwrite(students, sizeof(Student), n, fp);
    
    fclose(fp);
    free(students);
    
    printf("Database saved.\n");
    
    return 0;
}