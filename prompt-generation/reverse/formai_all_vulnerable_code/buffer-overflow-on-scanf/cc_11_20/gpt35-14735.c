//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct resume_data {
    char name[50];
    char email[50];
    char phone[20];
    char address[100];
    char education[100];
    char experience[100];
};

typedef struct resume_data RESUME_DATA;

int main(void) {

    char input_file[50];
    FILE *fp;

    printf("Enter the name of the input file: ");
    scanf("%s", input_file);

    fp = fopen(input_file, "r");

    if (fp == NULL) {
        printf("File not found!");
        exit(1);
    }

    int num_of_resumes = 0;
    char line[1000];

    while (fgets(line, 1000, fp)) {
        num_of_resumes++;
    }

    rewind(fp);

    RESUME_DATA resumes[num_of_resumes];

    int count = 0;
    int field_count = 0;
    char *token;

    while (fgets(line, 1000, fp)) {
        token = strtok(line, ":");

        while (token != NULL) {
            switch (field_count) {
                case 0:
                    strcpy(resumes[count].name, token);
                    field_count++;
                    break;
                case 1:
                    strcpy(resumes[count].email, token);
                    field_count++;
                    break;
                case 2:
                    strcpy(resumes[count].phone, token);
                    field_count++;
                    break;
                case 3:
                    strcpy(resumes[count].address, token);
                    field_count++;
                    break;
                case 4:
                    strcpy(resumes[count].education, token);
                    field_count++;
                    break;
                case 5:
                    strcpy(resumes[count].experience, token);
                    field_count++;
                    break;
                default:
                    break;
            }

            token = strtok(NULL, ":");
        }

        count++;
        field_count = 0;
    }

    fclose(fp);

    printf("\nParsed Resume Data:\n");
    printf("--------------------\n\n");

    for (int i = 0; i < num_of_resumes; i++) {
        printf("Resume #%d:\n", (i + 1));
        printf("Name: %s", resumes[i].name);
        printf("Email: %s", resumes[i].email);
        printf("Phone: %s", resumes[i].phone);
        printf("Address: %s", resumes[i].address);
        printf("Education: %s", resumes[i].education);
        printf("Experience: %s", resumes[i].experience);
        printf("\n");
    }

    return 0;
}