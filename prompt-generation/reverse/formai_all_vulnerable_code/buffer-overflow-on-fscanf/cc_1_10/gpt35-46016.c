//FormAI DATASET v1.0 Category: Database simulation ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct record {
    int id;
    char name[50];
    float rating;
} Record;

int menu() {
    int choice;
    printf("\nC Database Simulation Example Program\n");
    printf("1. Create Database\n");
    printf("2. Read from Database\n");
    printf("3. Update Record in Database\n");
    printf("4. Delete Record from Database\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    return choice;
}

int main() {
    int choice, i, n, id, found;
    char name[50];
    float rating;
    FILE *fp;
    Record rec;
    while (1) {
        choice = menu();
        switch(choice) {
            case 1:
                fp = fopen("database.txt", "w");
                if (fp == NULL) {
                    printf("Error creating database file!\n");
                    exit(1);
                }
                printf("\nEnter the number of records you want to add to the database: ");
                scanf("%d", &n);
                for (i = 0; i < n; i++) {
                    printf("\nRecord %d:\n", i+1);
                    printf("Enter ID: ");
                    scanf("%d", &rec.id);
                    printf("Enter Name: ");
                    scanf("%s", rec.name);
                    printf("Enter Rating: ");
                    scanf("%f", &rec.rating);
                    fprintf(fp, "%d %s %.2f\n", rec.id, rec.name, rec.rating);
                }
                fclose(fp);
                printf("\nDatabase created successfully!\n");
                break;
            case 2:
                fp = fopen("database.txt", "r");
                if (fp == NULL) {
                    printf("Database file not found!\n");
                    break;
                }
                printf("\nID\tName\t\tRating\n");
                printf("----------------------------------------\n");
                while (fscanf(fp, "%d %s %f", &rec.id, rec.name, &rec.rating) != EOF) {
                    printf("%d\t%-15s\t%.2f\n", rec.id, rec.name, rec.rating);
                }
                fclose(fp);
                break;
            case 3:
                fp = fopen("database.txt", "r+");
                if (fp == NULL) {
                    printf("Database file not found!\n");
                    break;
                }
                found = 0;
                printf("\nEnter the ID of the record you want to update: ");
                scanf("%d", &id);
                while (fscanf(fp, "%d %s %f", &rec.id, rec.name, &rec.rating) != EOF) {
                    if (rec.id == id) {
                        printf("Enter new Name: ");
                        scanf("%s", rec.name);
                        printf("Enter new Rating: ");
                        scanf("%f", &rec.rating);
                        fseek(fp, -sizeof(rec), SEEK_CUR);
                        fprintf(fp, "%d %s %.2f\n", rec.id, rec.name, rec.rating);
                        found = 1;
                        break;
                    }
                }
                fclose(fp);
                if (found)
                    printf("\nRecord updated successfully!\n");
                else
                    printf("\nRecord not found!\n");
                break;
            case 4:
                fp = fopen("database.txt", "r+");
                if (fp == NULL) {
                    printf("Database file not found!\n");
                    break;
                }
                found = 0;
                printf("\nEnter the ID of the record you want to delete: ");
                scanf("%d", &id);
                while (fscanf(fp, "%d %s %f", &rec.id, rec.name, &rec.rating) != EOF) {
                    if (rec.id == id) {
                        found = 1;
                        break;
                    }
                }
                if (found) {
                    fseek(fp, -sizeof(rec), SEEK_CUR);
                    fprintf(fp, "        \n"); // overwrite the record with spaces
                    printf("\nRecord deleted successfully!\n");
                }
                else
                    printf("\nRecord not found!\n");
                fclose(fp);
                break;
            case 5:
                printf("\nThank you for using this program!\n");
                exit(0);
            default:
                printf("\nInvalid choice! Please choose again.\n");
        }
    }
    return 0;
}