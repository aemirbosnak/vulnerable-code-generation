//FormAI DATASET v1.0 Category: System process viewer ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    printf("O process! O process!\nWherefore art thou process?\nDeny thy fork and refuse thy name,\nOr if thou wilt not, be but sworn my love,\nAnd I'll no longer be a viewer.\n");

    FILE* fp;
    char path[100];
    char line[500];
    int pid;
    char pname[20];

    printf("Enter the process ID: ");
    scanf("%d", &pid);

    sprintf(path, "/proc/%d/cmdline", pid);
    fp = fopen(path, "r");

    if (fp == NULL) {
        printf("Process with ID %d does not exist.\n", pid);
        return 1;
    }

    fgets(line, sizeof(line), fp);
    fclose(fp);

    strcpy(pname, line);

    printf("What's in a name? That which we call a process\nBy any other name would smell as sweet;\n");

    printf("Process ID: %d\n", pid);
    printf("Process Name: %s\n", pname);

    sprintf(path, "/proc/%d/status", pid);
    fp = fopen(path, "r");

    if (fp == NULL) {
        printf("Unable to retrieve status for Process ID %d.\n", pid);
        return 1;
    }

    printf("Oh, be some other name! What's in a name?\nThat which we call a rose by any other name\nWould smell as sweet;\nSo Process Status -\n");

    while (fgets(line, sizeof(line), fp)) {
        if (strncmp(line, "State:", 6) == 0) {
            printf("Status: %s", &line[7]);
        }
    }

    printf("Good night, good night! Parting is such sweet sorrow\nThat I shall say good night till it be morrow\n");

    fclose(fp);
    return 0;
}