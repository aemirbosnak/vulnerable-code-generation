//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_INPUT_SIZE 100

int main() {

char user_input[MAX_INPUT_SIZE];
char sanitized_input[MAX_INPUT_SIZE];
printf("Please enter some text:\n");
fgets(user_input, MAX_INPUT_SIZE, stdin);
int len = strlen(user_input);
if (user_input[len-1] == '\n') {
    user_input[len-1] = '\0';
}

//Remove leading and trailing spaces
char *temp = user_input;
while (*temp == ' ') {
    temp++;
}
int i = 0;
while (*temp != '\0') {
    sanitized_input[i] = *temp;
    i++;
    temp++;
}
sanitized_input[i] = '\0';

//Remove non-alpha characters
temp = sanitized_input;
i = 0;
while (*temp != '\0') {
    if (isalpha(*temp)) {
        sanitized_input[i] = *temp;
        i++;
    }
    temp++;
}
sanitized_input[i] = '\0';

//Convert to lowercase
temp = sanitized_input;
i = 0;
while (*temp != '\0') {
    sanitized_input[i] = tolower(*temp);
    temp++;
    i++;
}
sanitized_input[i] = '\0';

printf("Sanitized input: %s\n", sanitized_input);

return 0;
}