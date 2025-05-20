//FormAI DATASET v1.0 Category: Database simulation ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Record {
    int id;
    char name[50];
    float salary;
} Record;

int main() {
    int option, id, i, n = 0;
    float salary;
    char name[50];

    FILE *fp;

    Record rec;

    while (1) {
        printf("\n Options: \n");
        printf(" 1. Add a record \n");
        printf(" 2. Display a record \n");
        printf(" 3. Display all records \n");
        printf(" 4. Delete a record \n");
        printf(" 5. Exit the program \n");

        printf("\n Enter an option: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                fp = fopen("database.txt", "a");
                printf("\n Enter id: ");
                scanf("%d", &id);
                printf("\n Enter name: ");
                scanf("%s", name);
                printf("\n Enter salary: ");
                scanf("%f", &salary);
                rec.id = id;
                strcpy(rec.name, name);
                rec.salary = salary;
                fwrite(&rec, sizeof(Record), 1, fp);
                fclose(fp);
                n++;
                break;

            case 2:
                fp = fopen("database.txt", "r");
                if (n == 0) {
                    printf("\n No records in the database\n");
                    break;
                }
                printf("\n Enter id: ");
                scanf("%d", &id);
                for (i = 0; i < n; i++) {
                    fread(&rec, sizeof(Record), 1, fp);
                    if (rec.id == id) {
                        printf("\n ID: %d \t Name: %s \t Salary: %f \n", rec.id, rec.name, rec.salary);
                        fclose(fp);
                        break;
                    }
                }
                if (i == n) {
                    printf("\n No matching records in the database\n");
                }
                break;

            case 3:
                fp = fopen("database.txt", "r");
                if (n == 0) {
                    printf("\n No records in the database\n");
                    break;
                }
                printf("\n ID \t Name \t\t Salary \n");
                for (i = 0; i < n; i++) {
                    fread(&rec, sizeof(Record), 1, fp);
                    printf(" %d \t %s \t %.2f \n", rec.id, rec.name, rec.salary);
                }
                fclose(fp);
                break;

            case 4:
                fp = fopen("database.txt", "r");
                FILE *temp = fopen("temp.txt", "w");
                if (n == 0) {
                    printf("\n No records in the database\n");
                    break;
                }
                printf("\n Enter id of the record to be deleted: ");
                scanf("%d", &id);
                for (i = 0; i < n; i++) {
                    fread(&rec, sizeof(Record), 1, fp);
                    if (rec.id == id)
                        continue;
                    fwrite(&rec, sizeof(Record), 1, temp);
                }
                fclose(fp);
                fclose(temp);
                remove("database.txt");
                rename("temp.txt", "database.txt");
                n--;
                break;

            case 5:
                printf("\n Exiting the program...\n");
                exit(0);

            default:
                printf("\n Invalid option\n");
                break;
        }
    }

    return 0;
}