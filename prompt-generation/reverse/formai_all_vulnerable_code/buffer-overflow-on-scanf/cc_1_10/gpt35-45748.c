//FormAI DATASET v1.0 Category: Database simulation ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100000
#define MAX_NAME 30

typedef struct {
    char name[MAX_NAME];
    int age;
    long int id;
} Person;

void saveData(Person p, int index) {
    FILE *fp;

    fp = fopen("database.bin", "rb+");
    if (fp == NULL) {
        fp = fopen("database.bin", "wb");
    }

    fseek(fp, index * sizeof(Person), SEEK_SET);
    fwrite(&p, sizeof(Person), 1, fp);

    fclose(fp);
}

Person getData(int index) {
    FILE *fp;
    Person p;

    fp = fopen("database.bin", "rb");
    if (fp == NULL) {
        printf("Cannot read database\n");
        exit(1);
    }

    fseek(fp, index * sizeof(Person), SEEK_SET);
    fread(&p, sizeof(Person), 1, fp);

    fclose(fp);

    return p;
}

int main(void) {
    int option, index;
    Person p;
    char c;
    int data_size = 0;

    while (1) {
        printf("\nSelect an option:\n1. Add data\n2. View data\n3. Quit\nOption: ");
        scanf("%d", &option);
        getchar();

        switch (option) {
            case 1:
                printf("\nEnter name: ");
                fgets(p.name, MAX_NAME, stdin);
                printf("Enter age: ");
                scanf("%d", &p.age);
                getchar();
                printf("Enter ID number: ");
                scanf("%ld", &p.id);
                getchar();

                saveData(p, data_size);
                data_size++;

                break;
            case 2:
                printf("\nEnter index: ");
                scanf("%d", &index);
                getchar();

                if (index >= data_size) {
                    printf("No data found\n");
                    break;
                }

                p = getData(index);
                printf("\nName: %s", p.name);
                printf("Age: %d\n", p.age);
                printf("ID Number: %ld\n", p.id);

                break;
            case 3:
                exit(0);
                break;
            default:
                printf("Invalid option\n");
        }
    }

    return 0;
}