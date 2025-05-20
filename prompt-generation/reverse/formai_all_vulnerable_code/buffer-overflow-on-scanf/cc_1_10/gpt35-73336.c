//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct resume {
    char name[30];
    char email[50];
    char phone[20];
    char address[100];
    char education[200];
    char experience[400];
    char skills[500];
};

void parse_resume(char *filename) {
    FILE *fp;
    char line[1000];
    struct resume res;
    int count = 0;

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return;
    }

    // loop through each line of the file
    while(fgets(line, 1000, fp)) {
        // identify the type of information on the line
        if (strstr(line, "Name:")) {
            strcpy(res.name, line+6); // copy the name into struct
            count++;
        } else if (strstr(line, "Email:")) {
            strcpy(res.email, line+7);
            count++;
        } else if (strstr(line, "Phone:")) {
            strcpy(res.phone, line+7);
            count++;
        } else if (strstr(line, "Address:")) {
            strcpy(res.address, line+9);
            count++;
        } else if (strstr(line, "Education:")) {
            strcpy(res.education, line+11);
            count++;
        } else if (strstr(line, "Experience:")) {
            strcpy(res.experience, line+12);
            count++;
        } else if (strstr(line, "Skills:")) {
            strcpy(res.skills, line+8);
            count++;
        }

        // check if all fields have been filled in
        if (count == 7) {
            // print out the parsed resume
            printf("\nName: %s", res.name);
            printf("Email: %s", res.email);
            printf("Phone: %s", res.phone);
            printf("Address: %s", res.address);
            printf("Education: %s", res.education);
            printf("Experience: %s", res.experience);
            printf("Skills: %s", res.skills);

            // reset count and struct for next resume
            count = 0;
            memset(&res, 0, sizeof(res));
        }
    }

    fclose(fp);
}

int main() {
    char filename[50];

    printf("Enter the filename of the resumes: ");
    scanf("%s", filename);

    parse_resume(filename);

    return 0;
}