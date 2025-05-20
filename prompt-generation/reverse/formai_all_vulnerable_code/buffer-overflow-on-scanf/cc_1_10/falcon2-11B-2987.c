//Falcon2-11B DATASET v1.0 Category: Database simulation ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to insert a record into the database
void insert_record(int id, char *name, int age) {
    FILE *fp;
    char record[100];
    fp = fopen("database.txt", "a");
    sprintf(record, "%d,%s,%d\n", id, name, age);
    fprintf(fp, "%s", record);
    fclose(fp);
}

// Function to retrieve a record from the database
void retrieve_record(int id) {
    FILE *fp;
    char record[100];
    fp = fopen("database.txt", "r");
    fgets(record, 100, fp);
    printf("Record for ID %d: %s\n", id, record);
    fclose(fp);
}

// Function to update a record in the database
void update_record(int id, char *name, int age) {
    FILE *fp;
    char record[100];
    fp = fopen("database.txt", "r");
    fgets(record, 100, fp);
    sprintf(record, "%d,%s,%d\n", id, name, age);
    fprintf(fp, "%s", record);
    fclose(fp);
}

// Function to delete a record from the database
void delete_record(int id) {
    FILE *fp;
    fp = fopen("database.txt", "r");
    char record[100];
    fgets(record, 100, fp);
    fclose(fp);
    fp = fopen("database.txt", "w");
    fprintf(fp, "");
    fclose(fp);
}

// Main program
int main() {
    int id;
    char name[20];
    int age;
    printf("Enter the ID: ");
    scanf("%d", &id);
    printf("Enter the name: ");
    scanf("%s", name);
    printf("Enter the age: ");
    scanf("%d", &age);
    insert_record(id, name, age);
    retrieve_record(id);
    update_record(id, name, age);
    delete_record(id);
    return 0;
}