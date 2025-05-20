//FormAI DATASET v1.0 Category: Data recovery tool ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct data_entry {
    char name[20];
    char type[10];
    int size;
    void* data;
};

void save_data_entry(struct data_entry entry) {
    FILE* file = fopen("data_recovery.bin", "ab");
    if (!file) {
        printf("Error: unable to open file\n");
        exit(1);
    }
    fwrite(&entry, sizeof(struct data_entry), 1, file);
    fclose(file);
}

void list_data_entries() {
    FILE* file = fopen("data_recovery.bin", "rb");
    if (!file) {
        printf("Error: unable to open file\n");
        return;
    }
    fseek(file, 0L, SEEK_END);
    long int end_pos = ftell(file);
    rewind(file);

    while (ftell(file) < end_pos) {
        struct data_entry entry;
        fread(&entry, sizeof(struct data_entry), 1, file);
        printf("%s (%s, %d bytes)\n", entry.name, entry.type, entry.size);
    }
    fclose(file);
}

struct data_entry recover_data_entry(char* name) {
    FILE* file = fopen("data_recovery.bin", "rb");
    if (!file) {
        printf("Error: unable to open file\n");
        exit(1);
    }
    fseek(file, 0L, SEEK_END);
    long int end_pos = ftell(file);
    rewind(file);

    while (ftell(file) < end_pos) {
        struct data_entry entry;
        fread(&entry, sizeof(struct data_entry), 1, file);
        if (strcmp(entry.name, name) == 0) {
            char* data = malloc(entry.size);
            fread(data, entry.size, 1, file);
            entry.data = data;
            fclose(file);
            return entry;
        }
        fseek(file, entry.size, SEEK_CUR);
    }
    printf("Error: no entry with name '%s' found\n", name);
    fclose(file);
    exit(1);
}

int main() {
    char choice;

    do {
        printf("\n1. Save data entry\n");
        printf("2. List data entries\n");
        printf("3. Recover data entry\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf(" %c", &choice);

        switch (choice) {
        case '1': {
            struct data_entry entry;
            printf("Enter name of entry (max 19 characters): ");
            scanf("%19s", entry.name);
            printf("Enter type of entry (max 9 characters): ");
            scanf("%9s", entry.type);
            printf("Enter size of data (in bytes): ");
            scanf("%d", &entry.size);
            entry.data = malloc(entry.size);
            printf("Enter data (max %d characters): ", entry.size);
            scanf("%*c%[^\n]", entry.data);
            save_data_entry(entry);
            printf("Data entry saved successfully\n");
            break;
        }
        case '2': {
            printf("\nList of data entries:\n");
            list_data_entries();
            break;
        }
        case '3': {
            char name[20];
            printf("Enter name of entry to recover: ");
            scanf("%19s", name);
            struct data_entry entry = recover_data_entry(name);
            printf("Data entry found: %s (%s, %d bytes)\n%s\n", entry.name, entry.type, entry.size, entry.data);
            free(entry.data);
            break;
        }
        case '4': {
            printf("Exiting program...\n");
            break;
        }
        default: {
            printf("Invalid choice, please try again\n");
            break;
        }
        }
    } while (choice != '4');

    return 0;
}