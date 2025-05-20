//FormAI DATASET v1.0 Category: File handling ; Style: retro
#include <stdio.h>
#include <string.h>

char data[256];

struct Record {
    char name[30];
    int age;
    char city[30];
};

void save_to_file(struct Record rec) {
    FILE *file = fopen("records.txt", "a");
    if (file == NULL) {
        printf("Error opening file\n");
        return;
    }
    fprintf(file, "%s,%d,%s\n", rec.name, rec.age, rec.city);
    printf("Record saved successfully\n");
    fclose(file);
}

void read_from_file() {
    FILE *file = fopen("records.txt", "r");
    if (file == NULL) {
        printf("Error opening file\n");
        return;
    }
    while (fgets(data, 256, file)) {
        printf("%s", data);
    }
    printf("\n");
    fclose(file);
}

int main() {
    int choice;
    struct Record rec;
    while (1) {
        printf("Press 1 to add record\n");
        printf("Press 2 to view records\n");
        printf("Press 0 to exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 0:
                return 0;
            case 1:
                printf("Enter name: ");
                scanf("%s", rec.name);
                printf("Enter age: ");
                scanf("%d", &rec.age);
                printf("Enter city: ");
                scanf("%s", rec.city);
                save_to_file(rec);
                break;
            case 2:
                read_from_file();
                break;
            default:
                printf("Invalid choice!\n");
                break;
        }
    }
    return 0;
}