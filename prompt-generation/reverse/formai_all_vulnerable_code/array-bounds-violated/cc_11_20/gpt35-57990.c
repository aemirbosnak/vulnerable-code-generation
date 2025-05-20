//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char* name;
    char* email;
    char* phone;
    char* address;
    char** skills;
    char** education;
    char** experience;
} Resume;

void parseResume(char* filepath, Resume* r) {
    // open resume file
    FILE* f = fopen(filepath, "r");
    if (f == NULL) {
        printf("Error: Unable to open file '%s'\n", filepath);
        exit(1);
    }

    // read resume data, line by line
    char buffer[1024];
    while (fgets(buffer, 1024, f)) {
        // remove newline character from end of line
        int len = strlen(buffer);
        if (buffer[len-1] == '\n')
            buffer[len-1] = '\0';

        // skip empty lines
        if (buffer[0] == '\0')
            continue;

        // parse line and set corresponding resume field
        char* token = strtok(buffer, ":");
        if (strcmp(token, "Name") == 0) {
            r->name = strdup(strtok(NULL, ":"));
        }
        else if (strcmp(token, "Email") == 0) {
            r->email = strdup(strtok(NULL, ":"));
        }
        else if (strcmp(token, "Phone") == 0) {
            r->phone = strdup(strtok(NULL, ":"));
        }
        else if (strcmp(token, "Address") == 0) {
            r->address = strdup(strtok(NULL, ":"));
        }
        else if (strcmp(token, "Skills") == 0) {
            // parse comma-separated list of skills
            char* skill_str = strtok(NULL, ":");
            int num_skills = 0;
            char* token;
            while ((token = strtok(skill_str, ",")) != NULL) {
                num_skills++;
                skill_str = NULL; // reset strtok usage
            }

            // allocate skills array and copy parsed skills
            r->skills = malloc((num_skills+1) * sizeof(char*));
            skill_str = strtok(strdup(strtok(NULL, ":")), ","); // second strtok is necessary to avoid whitespace bug
            for (int i = 0; i < num_skills; i++) {
                r->skills[i] = strdup(token);
                token = strtok(NULL, ",");
            }
            r->skills[num_skills] = NULL; // add terminating NULL pointer
        }
        else if (strcmp(token, "Education") == 0) {
            // parse comma-separated list of degrees
            char* degree_str = strtok(NULL, ":");
            int num_degrees = 0;
            char* token;
            while ((token = strtok(degree_str, ",")) != NULL) {
                num_degrees++;
                degree_str = NULL; // reset strtok usage
            }

            // allocate education array and copy parsed degrees
            r->education = malloc((num_degrees+1) * sizeof(char*));
            degree_str = strtok(strdup(strtok(NULL, ":")), ","); // second strtok is necessary to avoid whitespace bug
            for (int i = 0; i < num_degrees; i++) {
                r->education[i] = strdup(token);
                token = strtok(NULL, ",");
            }
            r->education[num_degrees] = NULL; // add terminating NULL pointer
        }
        else if (strcmp(token, "Experience") == 0) {
            // parse colon-separated tuple of job title, employer, and years
            char* job_str = strtok(NULL, ":");
            int num_jobs = 0;
            char* token;
            while ((token = strtok(job_str, ",")) != NULL) {
                num_jobs++;
                job_str = NULL; // reset strtok usage
            }

            // allocate experience array and copy parsed tuples
            r->experience = malloc((num_jobs+1) * sizeof(char*));
            job_str = strtok(strdup(strtok(NULL, ":")), ","); // second strtok is necessary to avoid whitespace bug
            for (int i = 0; i < num_jobs; i++) {
                char* job_title = strdup(token);
                char* employer = strdup(strtok(NULL, ","));
                char* years = strdup(strtok(NULL, ","));
                char* job_tuple = malloc(strlen(job_title) + strlen(employer) + strlen(years) + 4);
                sprintf(job_tuple, "%s, %s, %s", job_title, employer, years);
                r->experience[i] = job_tuple;
                token = strtok(NULL, ",");
            }
            r->experience[num_jobs] = NULL; // add terminating NULL pointer
        }
        else {
            printf("Warning: Unrecognized field '%s' in resume file '%s'\n", token, filepath);
        }
    }

    // close resume file
    fclose(f);
}

int main() {
    // parse example resume file
    Resume r;
    parseResume("example_resume.txt", &r);

    // print resume fields
    printf("Name: %s\n", r.name);
    printf("Email: %s\n", r.email);
    printf("Phone: %s\n", r.phone);
    printf("Address: %s\n", r.address);
    printf("Skills:\n");
    for (int i = 0; r.skills[i] != NULL; i++) {
        printf("  - %s\n", r.skills[i]);
    }
    printf("Education:\n");
    for (int i = 0; r.education[i] != NULL; i++) {
        printf("  - %s\n", r.education[i]);
    }
    printf("Experience:\n");
    for (int i = 0; r.experience[i] != NULL; i++) {
        printf("  - %s\n", r.experience[i]);
    }

    // free resume fields
    free(r.name);
    free(r.email);
    free(r.phone);
    free(r.address);
    for (int i = 0; r.skills[i] != NULL; i++) {
        free(r.skills[i]);
    }
    free(r.skills);
    for (int i = 0; r.education[i] != NULL; i++) {
        free(r.education[i]);
    }
    free(r.education);
    for (int i = 0; r.experience[i] != NULL; i++) {
        free(r.experience[i]);
    }
    free(r.experience);

    return 0;
}