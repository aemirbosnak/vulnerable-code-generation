//Falcon2-11B DATASET v1.0 Category: Resume Parsing System ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>

int main()
{
    FILE *fp;
    char line[1000];
    char *token;
    char *full_name;
    char *email;
    char *phone;
    char *address;
    char *education;
    char *skills;
    char *work_experience;
    char *personal;

    int i;

    fp = fopen("resume.txt", "r");

    if (fp == NULL)
    {
        printf("Unable to open file\n");
        return 1;
    }

    while (fgets(line, sizeof(line), fp))
    {
        token = strtok(line, ":");

        if (strcmp(token, "Name") == 0)
        {
            full_name = strtok(NULL, ":");
        }
        else if (strcmp(token, "Email") == 0)
        {
            email = strtok(NULL, ":");
        }
        else if (strcmp(token, "Phone") == 0)
        {
            phone = strtok(NULL, ":");
        }
        else if (strcmp(token, "Address") == 0)
        {
            address = strtok(NULL, ":");
        }
        else if (strcmp(token, "Education") == 0)
        {
            education = strtok(NULL, ":");
        }
        else if (strcmp(token, "Skills") == 0)
        {
            skills = strtok(NULL, ":");
        }
        else if (strcmp(token, "Work Experience") == 0)
        {
            work_experience = strtok(NULL, ":");
        }
        else if (strcmp(token, "Personal") == 0)
        {
            personal = strtok(NULL, ":");
        }

        i++;

        if (i >= 11)
        {
            break;
        }
    }

    fclose(fp);

    printf("Full Name: %s\n", full_name);
    printf("Email: %s\n", email);
    printf("Phone: %s\n", phone);
    printf("Address: %s\n", address);
    printf("Education: %s\n", education);
    printf("Skills: %s\n", skills);
    printf("Work Experience: %s\n", work_experience);
    printf("Personal: %s\n", personal);

    return 0;
}