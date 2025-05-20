//Gemma-7B DATASET v1.0 Category: Password management ; Style: mathematical
#include <stdio.h>
#include <string.h>

int main()
{
    char password[20];
    int i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z;

    printf("Enter a strong password: ");
    scanf("%s", password);

    for (i = 0; password[i] != '\0'; i++)
    {
        switch (password[i])
        {
            case 'a':
            case 'b':
            case 'c':
            case 'd':
            case 'e':
            case 'f':
            case 'g':
            case 'h':
            case 'i':
            case 'j':
            case 'k':
            case 'l':
            case 'm':
            case 'n':
            case 'o':
            case 'p':
            case 'q':
            case 'r':
            case 's':
            case 't':
            case 'u':
            case 'v':
            case 'w':
            case 'x':
            case 'y':
            case 'z':
                printf("Valid character.\n");
                break;

            default:
                printf("Invalid character.\n");
                break;
        }
    }

    return 0;
}