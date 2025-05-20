//FormAI DATASET v1.0 Category: Database simulation ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100

const char *DB_FILE_NAME = "db.dat";

typedef struct {
    int id;
    char name[30];
    int age;
} Record;

/*
 * This function reads a record from a file stream
 */
void read_record(FILE *fp, Record *rec) {
    fread(rec, sizeof(Record), 1, fp);
}

/*
 * This function writes a record to a file stream
 */
void write_record(FILE *fp, Record *rec) {
    fwrite(rec, sizeof(Record), 1, fp);
}

/*
 * This function opens the database file and returns a file pointer
 */
FILE *open_database() {
    FILE *fp = fopen(DB_FILE_NAME, "rb+");
    if (!fp) {
        fp = fopen(DB_FILE_NAME, "wb+");
        if (!fp) {
            printf("Failed to open database file\n");
            exit(1);
        }
    }
    return fp;
}

/*
 * This function adds a new record to the database
 */
void add_record() {
    Record rec;
    printf("Enter ID: ");
    scanf("%d", &rec.id);
    printf("Enter Name: ");
    scanf("%s", rec.name);
    printf("Enter Age: ");
    scanf("%d", &rec.age);

    FILE *fp = open_database();
    if (fp) {
        fseek(fp, 0, SEEK_END);
        write_record(fp, &rec);
        fclose(fp);
        printf("Record added successfully\n");
    }
}

/*
 * This function displays all the records in the database
 */
void display_all_records() {
    Record rec;
    FILE *fp = open_database();
    if (fp) {
        fseek(fp, 0, SEEK_SET);
        while (!feof(fp)) {
            read_record(fp, &rec);
            if (!feof(fp)) {
                printf("%d\t%s\t%d\n", rec.id, rec.name, rec.age);
            }
        }
        fclose(fp);
    }
}

/*
 * This function searches for a record by ID
 */
void search_record() {
    int id;
    printf("Enter ID to search: ");
    scanf("%d", &id);

    Record rec;
    FILE *fp = open_database();
    if (fp) {
        fseek(fp, 0, SEEK_SET);
        while (!feof(fp)) {
            read_record(fp, &rec);
            if (!feof(fp)) {
                if (rec.id == id) {
                    printf("%d\t%s\t%d\n", rec.id, rec.name, rec.age);
                    fclose(fp);
                    return;
                }
            }
        }
        fclose(fp);
    }
    printf("Record not found\n");
}

/*
 * This function updates a record by ID
 */
void update_record() {
    int id;
    printf("Enter ID to update: ");
    scanf("%d", &id);

    Record rec;
    FILE *fp = open_database();
    if (fp) {
        fseek(fp, 0, SEEK_SET);
        while (!feof(fp)) {
            read_record(fp, &rec);
            if (!feof(fp)) {
                if (rec.id == id) {
                    printf("Current Name: %s\n", rec.name);
                    printf("Enter New Name: ");
                    scanf("%s", rec.name);
                    printf("Current Age: %d\n", rec.age);
                    printf("Enter New Age: ");
                    scanf("%d", &rec.age);
                    fseek(fp, -sizeof(Record), SEEK_CUR);
                    write_record(fp, &rec);
                    fclose(fp);
                    printf("Record updated successfully\n");
                    return;
                }
            }
        }
        fclose(fp);
    }
    printf("Record not found\n");
}

/*
 * This function deletes a record by ID
 */
void delete_record() {
    int id;
    printf("Enter ID to delete: ");
    scanf("%d", &id);

    Record rec;
    FILE *fp = open_database();
    if (fp) {
        FILE *temp_fp = fopen("temp.dat", "wb");
        if (!temp_fp) {
            printf("Failed to create temporary file\n");
            fclose(fp);
            exit(1);
        }

        fseek(fp, 0, SEEK_SET);
        while (!feof(fp)) {
            read_record(fp, &rec);
            if (!feof(fp)) {
                if (rec.id != id) {
                    write_record(temp_fp, &rec);
                }
            }
        }

        fclose(fp);
        fclose(temp_fp);

        remove(DB_FILE_NAME);
        rename("temp.dat", DB_FILE_NAME);
        printf("Record deleted successfully\n");
    }
}

/*
 * This function displays the menu and executes the selected option
 */
void menu() {
    int choice;

    while (1) {
        printf("MENU:\n");
        printf("1. Add Record\n");
        printf("2. Display All Records\n");
        printf("3. Search Record\n");
        printf("4. Update Record\n");
        printf("5. Delete Record\n");
        printf("6. Quit\n");
        printf("Enter Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_record();
                break;
            case 2:
                display_all_records();
                break;
            case 3:
                search_record();
                break;
            case 4:
                update_record();
                break;
            case 5:
                delete_record();
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
}

int main() {
    menu();
    return 0;
}