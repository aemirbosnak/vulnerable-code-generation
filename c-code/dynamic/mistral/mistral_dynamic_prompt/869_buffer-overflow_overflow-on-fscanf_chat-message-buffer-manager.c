#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

void main() {
    char buffer[10];
    int i;

    printf("Enter your chat message:\n");

    fgets(buffer, sizeof(buffer), stdin);
    printf("Your message is: %s\n", buffer);

    for(i = 0; buffer[i] != '\0'; i++) {
        if(buffer[i] == '\n') {
            buffer[i] = '\0';
            break;
        }
    }

    printf("Modified message: %s\n", buffer);

    printf("Message length: %d\n", strlen(buffer));

    char* names[] = {"Alice", "Bob", "Charlie", "David"};
    printf("Available users: ");
    for(i = 0; i < 4; i++) {
        printf("%s ", names[i]);
    }
    printf("\n");

    printf("Please enter a user name to send your message:\n");
    fgets(buffer, sizeof(buffer), stdin);
    strcat(buffer, "\n");
    strcat(buffer, "\r");

    for(i = 0; i < 4; i++) {
        if(strcmp(buffer, names[i]) == 0) {
            printf("Sending message to %s\n", buffer);
            break;
        }
    }
}
