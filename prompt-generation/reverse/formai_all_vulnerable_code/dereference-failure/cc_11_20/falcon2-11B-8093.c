//Falcon2-11B DATASET v1.0 Category: Resume Parsing System ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <regex.h>
#include <sys/wait.h>

int main(int argc, char **argv) {
    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <resume_file>\n", argv[0]);
        return 1;
    }

    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
        fprintf(stderr, "Error opening file '%s': %s\n", argv[1], strerror(errno));
        return 1;
    }

    char line[256];
    while (fgets(line, sizeof(line), fp)) {
        if (strlen(line) == 0)
            continue;

        if (strncmp(line, "Name:", 5) == 0) {
            char *name = strchr(line, ':');
            if (name!= NULL)
                *name = '\0';

            printf("Name: %s\n", line);
        } else if (strncmp(line, "Email:", 6) == 0) {
            char *email = strchr(line, ':');
            if (email!= NULL)
                *email = '\0';

            printf("Email: %s\n", line);
        } else if (strncmp(line, "Phone:", 6) == 0) {
            char *phone = strchr(line, ':');
            if (phone!= NULL)
                *phone = '\0';

            printf("Phone: %s\n", line);
        } else if (strncmp(line, "Address:", 7) == 0) {
            char *address = strchr(line, ':');
            if (address!= NULL)
                *address = '\0';

            printf("Address: %s\n", line);
        } else if (strncmp(line, "Skills:", 6) == 0) {
            char *skills = strchr(line, ':');
            if (skills!= NULL)
                *skills = '\0';

            printf("Skills: %s\n", line);
        } else if (strncmp(line, "Experience:", 9) == 0) {
            char *experience = strchr(line, ':');
            if (experience!= NULL)
                *experience = '\0';

            printf("Experience: %s\n", line);
        }
    }

    fclose(fp);
    return 0;
}