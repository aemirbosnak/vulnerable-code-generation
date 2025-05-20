//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define SIZE 1000

int main()
{
    FILE *fp;
    char filename[20];
    char ch;
    char key;
    int i, j;
    int flag = 0;
    int count = 0;
    int key_size = 0;
    int shift = 0;
    clock_t start, end;
    double cpu_time_used;

    printf("Enter the name of the file to be encrypted: ");
    scanf("%s", filename);

    fp = fopen(filename, "r");

    if (fp == NULL)
    {
        printf("Error opening file!\n");
        exit(1);
    }

    printf("Enter the key to be used for encryption: ");
    scanf("%c", &key);

    while ((ch = fgetc(fp))!= EOF)
    {
        if (isalpha(ch))
        {
            if (isupper(ch))
            {
                ch = tolower(ch);
            }

            if (flag == 0)
            {
                start = clock();
                for (i = 0; i < 26; i++)
                {
                    if ((ch - i + key) % 26 == 0)
                    {
                        key_size = i;
                        flag = 1;
                        break;
                    }
                }

                if (flag == 0)
                {
                    key_size = 26;
                }

                end = clock();
                cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
                printf("Key size is %d\n", key_size);
                printf("Time taken to calculate key size is %lf seconds\n", cpu_time_used);
            }

            if (ch - key_size + 97 >= 97)
            {
                count++;
            }

            ch = ch + key_size;

            if (ch > 122)
            {
                ch = ch - 26;
            }

            fprintf(stdout, "%c", ch);
        }
        else
        {
            fprintf(stdout, "%c", ch);
        }
    }

    fclose(fp);

    return 0;
}