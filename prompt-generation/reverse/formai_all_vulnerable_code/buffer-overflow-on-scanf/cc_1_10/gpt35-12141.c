//FormAI DATASET v1.0 Category: File handling ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 1000

struct Record {
    char name[20];
    int age;
    float height;
};

int main() {
    FILE *fp;
    int numRecords = 0, choice;
    struct Record records[MAX_RECORDS];

    while (1) {
        printf("1. Add record\n");
        printf("2. Print records\n");
        printf("3. Save records to file\n");
        printf("4. Load records from file\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (numRecords == MAX_RECORDS) {
                    printf("Maximum record limit reached.\n");
                    break;
                }
                printf("Enter name: ");
                scanf("%s", records[numRecords].name);
                printf("Enter age: ");
                scanf("%d", &records[numRecords].age);
                printf("Enter height: ");
                scanf("%f", &records[numRecords].height);
                numRecords++;
                break;
            case 2:
                printf("Name\tAge\tHeight\n");
                for (int i = 0; i < numRecords; i++) {
                    printf("%s\t%d\t%.2f\n", records[i].name, records[i].age, records[i].height);
                }
                break;
            case 3:
                fp = fopen("records.dat", "wb");
                fwrite(&numRecords, sizeof(int), 1, fp);
                fwrite(records, sizeof(struct Record), numRecords, fp);
                fclose(fp);
                printf("Records saved to file.\n");
                break;
            case 4:
                fp = fopen("records.dat", "rb");
                if (fp == NULL) {
                    printf("Records file not found.\n");
                    break;
                }
                fread(&numRecords, sizeof(int), 1, fp);
                fread(records, sizeof(struct Record), numRecords, fp);
                fclose(fp);
                printf("Records loaded from file.\n");
                break;
            case 5:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}