//MISTRAL-7B DATASET v1.0 Category: File handling ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Data {
    int id;
    char name[50];
    float price;
} Data;

void write_data(const char *filename, const Data data);
Data read_data(const char *filename);
void print_menu();

int main() {
    char filename[50];
    int choice;
    Data data;

    print_menu();
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Enter file name: ");
            scanf("%s", filename);
            printf("Enter data:\nID: ");
            scanf("%d", &data.id);
            printf("Name: ");
            scanf("%s", data.name);
            printf("Price: ");
            scanf("%f", &data.price);
            write_data(filename, data);
            printf("Data written successfully!\n");
            break;
        case 2:
            printf("Enter file name: ");
            scanf("%s", filename);
            data = read_data(filename);
            if (data.id != -1) {
                printf("ID: %d\n", data.id);
                printf("Name: %s\n", data.name);
                printf("Price: %.2f\n", data.price);
            } else {
                printf("Error: Invalid data in file.\n");
            }
            break;
        case 3:
            printf("Exiting program...\n");
            exit(0);
            break;
        default:
            printf("Invalid choice. Please try again.\n");
            break;
    }

    return 0;
}

void print_menu() {
    printf("\n1. Write data to file\n");
    printf("2. Read data from file\n");
    printf("3. Exit\n");
}

void write_data(const char *filename, const Data data) {
    FILE *file = fopen(filename, "wb");

    if (file == NULL) {
        perror("Error: Unable to open file for writing.");
        exit(1);
    }

    fwrite(&data, sizeof(Data), 1, file);
    fclose(file);
}

Data read_data(const char *filename) {
    FILE *file = fopen(filename, "rb");
    Data data;

    if (file == NULL) {
        perror("Error: Unable to open file for reading.");
        data.id = -1;
        return data;
    }

    if (fread(&data, sizeof(Data), 1, file) != 1) {
        perror("Error: Invalid data in file.");
        data.id = -1;
    }

    fclose(file);

    return data;
}