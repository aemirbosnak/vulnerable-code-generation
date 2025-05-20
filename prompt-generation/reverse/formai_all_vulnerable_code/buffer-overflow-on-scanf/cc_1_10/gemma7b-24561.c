//Gemma-7B DATASET v1.0 Category: Password Strength Checker ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main()
{
    char password[256];
    char *ptr;
    int strength = 0;

    printf("Good evening, Mr. Holmes. What is the password you wish to check?\n");
    scanf("%s", password);

    ptr = password;

    // Inspecting the password for minimum length
    if (strlen(ptr) < 8)
    {
        strength++;
        printf("Hmm... the password is a bit short, Mr. Watson. Eight characters are the minimum.\n");
    }

    // Checking for upper case letters
    if (strpbrk(ptr, "ABCDEFGHIJKLMNOPQRSTUVWXYZ") != NULL)
    {
        strength++;
        printf("The password has an uppercase letter, which is good.\n");
    }

    // Checking for lowercase letters
    if (strpbrk(ptr, "abcdefghijklmnopqrstuvwxyz") != NULL)
    {
        strength++;
        printf("The password has a lowercase letter, which is also good.\n");
    }

    // Checking for numbers
    if (strpbrk(ptr, "0123456789") != NULL)
    {
        strength++;
        printf("The password has a number, which is a bonus.\n");
    }

    // Inspecting for special characters
    if (strpbrk(ptr, "!@#$%^&*())_+-={}[]|\\:") != NULL)
    {
        strength++;
        printf("The password has a special character, which makes it even more robust.\n");
    }

    // Determining the overall strength
    switch (strength)
    {
        case 0:
            printf("Mr. Holmes, I'm afraid this password is as weak as a goose's feather.\n");
            break;
        case 1:
            printf("The password is a bit weak, but it has one redeeming quality, such as a number or a special character.\n");
            break;
        case 2:
            printf("The password is strong, Mr. Holmes. It has both upper and lowercase letters.\n");
            break;
        case 3:
            printf("Excellent, Mr. Holmes, the password is very strong. It has all the elements of a perfect password.\n");
            break;
    }

    return 0;
}