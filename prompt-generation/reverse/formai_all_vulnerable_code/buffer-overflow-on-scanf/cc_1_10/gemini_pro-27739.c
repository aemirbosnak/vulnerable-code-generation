//GEMINI-pro DATASET v1.0 Category: Error handling ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum {
    SUCCESS,
    FAILURE
} Status;

typedef struct {
    char *name;
    char *description;
} Evidence;

Status find_evidence(char *suspect, Evidence **evidence) {
    FILE *file;
    char line[1024];
    char *token;

    file = fopen("evidence.txt", "r");
    if (file == NULL) {
        fprintf(stderr, "Failed to open evidence file.\n");
        return FAILURE;
    }

    while (fgets(line, sizeof(line), file) != NULL) {
        token = strtok(line, ",");
        if (token == NULL) {
            fprintf(stderr, "Invalid evidence file format.\n");
            fclose(file);
            return FAILURE;
        }

        if (strcmp(token, suspect) == 0) {
            *evidence = malloc(sizeof(Evidence));
            if (*evidence == NULL) {
                fprintf(stderr, "Failed to allocate memory for evidence.\n");
                fclose(file);
                return FAILURE;
            }

            (*evidence)->name = strtok(NULL, ",");
            if ((*evidence)->name == NULL) {
                fprintf(stderr, "Invalid evidence file format.\n");
                free(*evidence);
                fclose(file);
                return FAILURE;
            }

            (*evidence)->description = strtok(NULL, "\n");
            if ((*evidence)->description == NULL) {
                fprintf(stderr, "Invalid evidence file format.\n");
                free((*evidence)->name);
                free(*evidence);
                fclose(file);
                return FAILURE;
            }

            fclose(file);
            return SUCCESS;
        }
    }

    fprintf(stderr, "No evidence found for suspect %s.\n", suspect);
    fclose(file);
    return FAILURE;
}

int main(void) {
    char suspect[1024];
    Evidence *evidence;
    Status status;

    printf("Enter the name of the suspect: ");
    scanf("%s", suspect);

    status = find_evidence(suspect, &evidence);
    if (status == SUCCESS) {
        printf("Evidence found for %s:\n", suspect);
        printf("Name: %s\n", evidence->name);
        printf("Description: %s\n", evidence->description);
        free(evidence->name);
        free(evidence);
    } else {
        printf("No evidence found for %s.\n", suspect);
    }

    return 0;
}