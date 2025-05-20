#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

void log_message(char *buffer, int size) {
    char log_file[200] = "log.txt";
    FILE *fp = fopen(log_file, "a");

    if (fp != NULL) {
        fprintf(fp, "%s\n", buffer);
        fclose(fp);
    }
}

int main() {
    char input[10];
    int level, severity;
    char *message;

    printf("Enter log level (1: info, 2: warning, 3: error): ");
    scanf("%d", &level);

    printf("Enter log message: ");
    fgets(input, sizeof(input), stdin);

    message = (char *)malloc((strlen(input) + 1) * (level + 1));
    strcpy(message, input);

    for (severity = 1; severity <= level; severity++) {
        strcat(message, "\n#");
        strcat(message, severity >= 3 ? "ERROR" : "WARNING");
    }

    sscanf(message, "%s %n", message, &message);

    log_message(message, strlen(message));

    free(message);
    return 0;
}
