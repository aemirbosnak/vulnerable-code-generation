//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/* puzzle pieces */
#define BLANK " "
#define EQ " == "
#define PLUS " + "
#define GT " > "
#define AND " && "
#define PASSWORD "password"
#define INDENT "    "

/* puzzle instructions */
char* instructions[] = {
    "=== PASSWORD STRENGTH CHECKER ===",
    "Enter the password you would like to check: ",
    "",
    "Checking password strength...",
    "",
    "PASSWORD STRENGTH:",
    INDENT "Number of characters" GT "8:",
    INDENT INDENT "strlen(password)" GT "8",
    INDENT "Contains uppercase letters:",
    INDENT INDENT "strchr(password, 'A')" EQ "NULL",
    INDENT "Contains lowercase letters:",
    INDENT INDENT "strchr(password, 'a')" EQ "NULL",
    INDENT "Contains numbers",
    INDENT INDENT "strchr(password, '0')" EQ "NULL",
    INDENT "Contains symbols (!, @, $, %, ^, &, *, (, )),",
    INDENT INDENT "strchr(password, '!') != NULL" AND "strchr(password, '@') != NULL" AND "strchr(password, '$') != NULL" AND "strchr(password, '%') != NULL" AND "strchr(password, '^') != NULL" AND "strchr(password, '&') != NULL" AND "strchr(password, '*') != NULL" AND "strchr(password, '(') != NULL" AND "strchr(password, ')') != NULL",
    "",
    "Enter any key to exit..."
};

/* main function */
int main(void) {
    char password[50];
    int num_chars, has_upper, has_lower, has_number, has_symbol;

    /* print puzzle instructions */
    printf("%s\n", instructions[0]);
    printf("%s", instructions[1]);
    scanf("%s", password);
    printf("\n%s\n\n", instructions[3]);

    /* check password strength */
    num_chars = strlen(password) > 8;
    has_upper = strchr(password, 'A') == NULL;
    has_lower = strchr(password, 'a') == NULL;
    has_number = strchr(password, '0') == NULL;
    has_symbol = strchr(password, '!') != NULL && strchr(password, '@') != NULL && strchr(password, '$') != NULL && strchr(password, '%') != NULL && strchr(password, '^') != NULL && strchr(password, '&') != NULL && strchr(password, '*') != NULL && strchr(password, '(') != NULL && strchr(password, ')') != NULL;

    /* display password strength */
    printf("%s\n", instructions[5]);
    printf("%s%s%d\n", instructions[6], INDENT, num_chars);
    printf("%s%s%s%sNULL\n", instructions[7], INDENT, INDENT, has_upper ? "" : "!");
    printf("%s%s%s%sNULL\n", instructions[8], INDENT, INDENT, has_lower ? "" : "!");
    printf("%s%s%s%sNULL\n", instructions[9], INDENT, INDENT, has_number ? "" : "!");
    printf("%s%s%s%sNULL\n", instructions[10], INDENT, INDENT, has_symbol ? "" : "!");

    /* wait for user input before exiting */
    printf("\n%s", instructions[12]);
    getchar();
    return 0;
}