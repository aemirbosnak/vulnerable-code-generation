//FormAI DATASET v1.0 Category: Database querying ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char name[50];
    int age;
    char city[30];
} Person;

int main() {
    int option;
    do {
        printf("MENU\n");
        printf("1. Search for a specific person\n");
        printf("2. List all people in a specific city\n");
        printf("3. List all people above a specific age threshold\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &option);

        switch(option) {
            case 1: {
                int id;
                printf("Enter the ID of the person you want to search for: ");
                scanf("%d", &id);

                FILE *fp = fopen("people.dat", "rb");
                Person p;
                int found = 0;
                while(fread(&p, sizeof(p), 1, fp)) {
                    if(p.id == id) {
                        found = 1;
                        printf("ID: %d\n", p.id);
                        printf("Name: %s\n", p.name);
                        printf("Age: %d\n", p.age);
                        printf("City: %s\n", p.city);
                        break;
                    }
                }
                if(!found) {
                    printf("No person with that ID was found.\n");
                }
                fclose(fp);
                break;
            }
            case 2: {
                char city[30];
                printf("Enter the name of the city you want to list people for: ");
                scanf("%s", city);

                FILE *fp = fopen("people.dat", "rb");
                Person p;
                int found = 0;
                while(fread(&p, sizeof(p), 1, fp)) {
                    if(strcmp(p.city, city) == 0) {
                        found = 1;
                        printf("ID: %d\n", p.id);
                        printf("Name: %s\n", p.name);
                        printf("Age: %d\n", p.age);
                        printf("City: %s\n", p.city);
                    }
                }
                if(!found) {
                    printf("No people found for that city.\n");
                }
                fclose(fp);
                break;
            }
            case 3: {
                int threshold;
                printf("Enter the age threshold: ");
                scanf("%d", &threshold);

                FILE *fp = fopen("people.dat", "rb");
                Person p;
                int found = 0;
                while(fread(&p, sizeof(p), 1, fp)) {
                    if(p.age > threshold) {
                        found = 1;
                        printf("ID: %d\n", p.id);
                        printf("Name: %s\n", p.name);
                        printf("Age: %d\n", p.age);
                        printf("City: %s\n", p.city);
                    }
                }
                if(!found) {
                    printf("No people found above that age threshold.\n");
                }
                fclose(fp);
                break;
            }
            case 4: {
                printf("Exiting...\n");
                exit(0);
            }
            default: {
                printf("Invalid option.\n");
                break;
            }
        }
    } while(1);
    return 0;
}