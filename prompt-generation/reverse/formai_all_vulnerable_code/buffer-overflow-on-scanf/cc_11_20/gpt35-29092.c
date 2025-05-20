//FormAI DATASET v1.0 Category: Database simulation ; Style: thoughtful
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Person {
    char name[100];
    int age;
    char gender;
};

int main() {
    FILE* fp;
    struct Person p;
    int choice, n, i;
    char temp[100];
    
    fp = fopen("person_db.txt", "w");

    if(fp == NULL) {
        printf("Error in opening file.");
        exit(0);
    }

    printf("Enter number of persons: ");
    scanf("%d", &n);

    for(i=0; i<n; i++) {
        printf("Person %d\n", i+1);
        printf("Enter Name: ");
        scanf("%s", p.name);
        printf("Enter Age: ");
        scanf("%d", &p.age);
        printf("Enter Gender (M/F): ");
        scanf(" %c", &p.gender);

        fwrite(&p, sizeof(struct Person), 1, fp);
    }

    fclose(fp);

    printf("\n------------------------------\n");
    printf("1) Modify Person's Age\n");
    printf("2) Modify Person's Gender\n");
    printf("3) Display Persons\n");
    printf("4) Exit\n");
    printf("------------------------------\n");

    while(1) {
        printf("Enter Choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                fp = fopen("person_db.txt", "r+");
                printf("Enter Person's Name: ");
                scanf("%s", temp);

                while(fread(&p, sizeof(struct Person), 1, fp)) {
                    if(strncmp(p.name, temp, strlen(temp)) == 0) {
                        printf("Enter New Age: ");
                        scanf("%d", &p.age);

                        fseek(fp, -sizeof(struct Person), SEEK_CUR);
                        fwrite(&p, sizeof(struct Person), 1, fp);
                        fseek(fp, 0, SEEK_SET);
                        break;
                    }
                }

                fclose(fp);
                break;

            case 2:
                fp = fopen("person_db.txt", "r+");
                printf("Enter Person's Name: ");
                scanf("%s", temp);

                while(fread(&p, sizeof(struct Person), 1, fp)) {
                    if(strncmp(p.name, temp, strlen(temp)) == 0) {
                        printf("Enter New Gender (M/F): ");
                        scanf(" %c", &p.gender);

                        fseek(fp, -sizeof(struct Person), SEEK_CUR);
                        fwrite(&p, sizeof(struct Person), 1, fp);
                        fseek(fp, 0, SEEK_SET);
                        break;
                    }
                }

                fclose(fp);
                break;

            case 3:
                fp = fopen("person_db.txt", "r");

                printf("\n\nAll Persons:\n");
                printf("-----------------------------\n");
                printf("| Name | Age | Gender |\n");
                printf("-----------------------------\n");

                while(fread(&p, sizeof(struct Person), 1, fp)) {
                    printf("| %s | %d | %c |\n", p.name, p.age, p.gender);
                }

                printf("-----------------------------\n");

                fclose(fp);
                break;

            case 4:
                printf("Exiting program.");
                exit(0);
                break;

            default:
                printf("Invalid Choice!\n");
                break;
        }
    }

    return 0;
}