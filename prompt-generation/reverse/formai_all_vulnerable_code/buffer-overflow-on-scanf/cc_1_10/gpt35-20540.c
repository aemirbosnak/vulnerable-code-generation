//FormAI DATASET v1.0 Category: Database simulation ; Style: Ken Thompson
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Student {
    int id;
    char name[50];
    float marks;
};

int main() {
    int choice;
    FILE *fp;
    struct Student s;
    int n, i, id;
    float marks;
    char name[50];

    while(1) {
        printf("\n1. Add Record\n2. Search Record\n3. Display Records\n4. Exit\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:     //To add record
                fp = fopen("students.dat", "ab");
                printf("\nEnter student id, name and marks\n");
                scanf("%d %s %f", &s.id, s.name, &s.marks);
                fwrite(&s, sizeof(s), 1, fp);
                fclose(fp);
                break;

            case 2:     //To search for a record
                fp = fopen("students.dat", "rb");
                printf("\nEnter student id to search: ");
                scanf("%d", &id);

                while(fread(&s, sizeof(s), 1, fp)) {
                    if(s.id == id) {
                        printf("\nStudent Details: \n");
                        printf("ID: %d\nName: %s\nMarks: %.2f\n", s.id, s.name, s.marks);
                        break;
                    }
                }

                if (feof(fp)) {
                    printf("\nRecord not found\n");
                }

                fclose(fp);
                break;

            case 3:     //To display all records
                fp = fopen("students.dat", "rb");

                while(fread(&s, sizeof(s), 1, fp)) {
                    printf("\nStudent Details: \n");
                    printf("ID: %d\nName: %s\nMarks: %.2f\n", s.id, s.name, s.marks);
                }

                fclose(fp);
                break;

            case 4:     //To exit
                exit(0);
                break;
                
            default:
                printf("\nInvalid choice\n");
                break;
        }
    }
    return 0;
}