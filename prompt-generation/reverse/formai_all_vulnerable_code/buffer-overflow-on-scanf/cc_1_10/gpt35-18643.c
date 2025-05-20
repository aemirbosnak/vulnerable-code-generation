//FormAI DATASET v1.0 Category: Database simulation ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char name[20];
    int age;
} Person;

int main() {
    FILE* fp;
    Person p;
    char filename[] = "database.bin";
    int choice, found = 0;

    while(1) {
        printf("\nMenu\n");
        printf("1. Add Person\n");
        printf("2. Search Person\n");
        printf("3. Display All\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        fflush(stdin);

        switch(choice) {
            case 1:
                fp = fopen(filename, "ab");
                printf("Enter ID: ");
                scanf("%d", &p.id);
                fflush(stdin);
                printf("Enter Name: ");
                fgets(p.name, sizeof(p.name), stdin);
                printf("Enter Age: ");
                scanf("%d", &p.age);
                fwrite(&p, sizeof(Person), 1, fp);
                fclose(fp);
                break;

            case 2:
                fp = fopen(filename, "rb");
                printf("Enter ID to search: ");
                int search_id;
                scanf("%d", &search_id);

                while(fread(&p, sizeof(Person), 1, fp)) {
                    if(p.id == search_id) {
                        printf("ID: %d\n", p.id);
                        printf("Name: %s", p.name);
                        printf("Age: %d\n", p.age);
                        found = 1;
                        break;
                    }
                }

                if(found == 0) {
                    printf("Person not found\n");
                }

                fclose(fp);
                break;

            case 3:
                fp = fopen(filename, "rb");

                while(fread(&p, sizeof(Person), 1, fp)) {
                    printf("ID: %d\n", p.id);
                    printf("Name: %s", p.name);
                    printf("Age: %d\n", p.age);
                }

                fclose(fp);
                break;

            case 4:
                printf("Exiting Program\n");
                exit(0);
                break;

            default:
                printf("Invalid Choice\n");
                break;
        }
    }

    return 0;
}