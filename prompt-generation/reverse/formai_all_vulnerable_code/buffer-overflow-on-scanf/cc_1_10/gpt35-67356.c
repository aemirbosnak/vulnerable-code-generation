//FormAI DATASET v1.0 Category: Data recovery tool ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char name[20];
    int age;
    char gender;
} Person;

void writeToFile();
void searchById();
void searchByName();
void recoverData();

int main() {
    int option;

    printf("Welcome to Data Recovery Tool\n");
    printf("-----------------------------\n");
    printf("1. Write data to file\n");
    printf("2. Search data by ID\n");
    printf("3. Search data by name\n");
    printf("4. Recover data\n");
    printf("5. Exit\n");

    while(1){
        printf("Enter option: ");
        scanf("%d", &option);
        switch(option) {
            case 1:
                writeToFile();
                break;
            case 2:
                searchById();
                break;
            case 3:
                searchByName();
                break;
            case 4:
                recoverData();
                break;
            case 5:
                printf("Thank you for using Data Recovery Tool\n");
                exit(0);
            default:
                printf("Invalid option, please try again\n");
        }
    }
    return 0;
}

void writeToFile() {
    FILE *fp;
    char filename[20];
    Person person;

    printf("Enter filename to write data: ");
    scanf("%s", filename);

    fp = fopen(filename, "wb");

    printf("Enter ID, name, age and gender of person to write to file\n");
    scanf("%d %s %d %c", &person.id, person.name, &person.age, &person.gender);

    fwrite(&person, sizeof(person), 1, fp);

    fclose(fp);
    printf("Successfully wrote data to file\n");
}

void searchById() {
    FILE *fp;
    char filename[20];
    int searchId;
    Person person;

    printf("Enter filename to search data: ");
    scanf("%s", filename);

    fp = fopen(filename, "rb");

    printf("Enter ID to search: ");
    scanf("%d", &searchId);

    while(fread(&person, sizeof(person), 1, fp)) {
        if(person.id == searchId) {
            printf("ID: %d, Name: %s, Age: %d, Gender: %c\n", person.id, person.name, person.age, person.gender);
            fclose(fp);
            return;
        }
    }

    printf("No data found with ID: %d\n", searchId);

    fclose(fp);
}

void searchByName() {
    FILE *fp;
    char filename[20];
    char searchName[20];
    Person person;

    printf("Enter filename to search data: ");
    scanf("%s", filename);

    fp = fopen(filename, "rb");

    printf("Enter name to search: ");
    scanf("%s", searchName);

    while(fread(&person, sizeof(person), 1, fp)) {
        if(strcmp(person.name, searchName) == 0) {
            printf("ID: %d, Name: %s, Age: %d, Gender: %c\n", person.id, person.name, person.age, person.gender);
        }
    }

    fclose(fp);
}

void recoverData() {
    FILE *fp1, *fp2;
    char filename1[20], filename2[20];
    Person person;

    printf("Enter filename to recover data from: ");
    scanf("%s", filename1);

    fp1 = fopen(filename1, "rb");

    if(fp1 == NULL) {
        printf("File not found: %s\n", filename1);
        return;
    }

    printf("Enter filename to recover data to: ");
    scanf("%s", filename2);

    fp2 = fopen(filename2, "wb");

    while(fread(&person, sizeof(person), 1, fp1)) {
        if(person.id % 2 == 0) {
            fwrite(&person, sizeof(person), 1, fp2);
        }
    }

    printf("Data recovery successful\n");

    fclose(fp1);
    fclose(fp2);
}