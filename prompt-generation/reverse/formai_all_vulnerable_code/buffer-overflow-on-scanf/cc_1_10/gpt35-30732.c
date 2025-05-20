//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *thread1(void *arg);
void *thread2(void *arg);
void *thread3(void *arg);

int main()
{
    pthread_t t1, t2, t3;
    char hex[10];
    printf("Enter Hexadecimal Number: ");
    scanf("%s", hex);
    pthread_create(&t1, NULL, thread1, (void *)hex);
    pthread_create(&t2, NULL, thread2, (void *)hex);
    pthread_create(&t3, NULL, thread3, (void *)hex);
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    pthread_join(t3, NULL);
    return 0;
}

void *thread1(void *arg)
{
    char *hex = (char *)arg;
    printf("\nASCII Values of Hexadecimal digits are: ");
    for (int i = 0; hex[i] != '\0'; i++)
    {
        printf("%d ", hex[i]);
    }
    pthread_exit(NULL);
}

void *thread2(void *arg)
{
    char *hex = (char *)arg;
    printf("\nDecimal Equivalent of Hexadecimal Number is: %d\n", (int)strtol(hex, NULL, 16));
    pthread_exit(NULL);
}

void *thread3(void *arg)
{
    char *hex = (char *)arg;
    printf("\nBinary Equivalent of Hexadecimal Number is: ");
    for (int i = 0; hex[i] != '\0'; i++)
    {
        switch (hex[i])
        {
        case '0':
            printf("0000");
            break;
        case '1':
            printf("0001");
            break;
        case '2':
            printf("0010");
            break;
        case '3':
            printf("0011");
            break;
        case '4':
            printf("0100");
            break;
        case '5':
            printf("0101");
            break;
        case '6':
            printf("0110");
            break;
        case '7':
            printf("0111");
            break;
        case '8':
            printf("1000");
            break;
        case '9':
            printf("1001");
            break;
        case 'a':
        case 'A':
            printf("1010");
            break;
        case 'b':
        case 'B':
            printf("1011");
            break;
        case 'c':
        case 'C':
            printf("1100");
            break;
        case 'd':
        case 'D':
            printf("1101");
            break;
        case 'e':
        case 'E':
            printf("1110");
            break;
        case 'f':
        case 'F':
            printf("1111");
            break;
        default:
            printf("\nInvalid Hexadecimal Number");
            pthread_exit(NULL);
        }
    }
    pthread_exit(NULL);
}