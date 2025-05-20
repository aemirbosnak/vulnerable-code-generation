//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MIN_PW_LEN 8
#define MAX_PW_LEN 16

char *generate_password(int min_len, int max_len);

int main()
{
    int pw_len;
    char *pw;

    srand(time(NULL));

    printf("How long do you want your password to be (between %d and %d characters)? ", MIN_PW_LEN, MAX_PW_LEN);
    scanf("%d", &pw_len);

    if (pw_len >= MIN_PW_LEN && pw_len <= MAX_PW_LEN)
    {
        pw = generate_password(pw_len, pw_len);
        printf("Your password is: %s\n", pw);
        free(pw);
    }
    else
    {
        printf("Invalid input. Password length must be between %d and %d characters.\n", MIN_PW_LEN, MAX_PW_LEN);
    }

    return 0;
}

char *generate_password(int min_len, int max_len)
{
    char *pw = NULL;
    int pw_len = (rand() % (max_len - min_len + 1)) + min_len;

    pw = (char *)malloc((pw_len + 1) * sizeof(char));

    if (pw == NULL)
    {
        perror("malloc");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < pw_len; i++)
    {
        int random_num = rand() % 100;

        if (random_num < 33)
        {
            pw[i] = rand() % 26 + 'a';
        }
        else if (random_num < 66)
        {
            pw[i] = rand() % 26 + 'A';
        }
        else
        {
            pw[i] = rand() % 10 + '0';
        }
    }

    pw[pw_len] = '\0';

    return pw;
}