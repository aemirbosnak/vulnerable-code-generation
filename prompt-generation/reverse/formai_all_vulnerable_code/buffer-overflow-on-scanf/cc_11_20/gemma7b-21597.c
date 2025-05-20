//Gemma-7B DATASET v1.0 Category: Phone Book ; Style: mathematical
#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        int num, count = 0;
        scanf("%d", &num);
        while(num)
        {
            int digit = num % 10;
            num /= 10;
            count++;
            switch(digit)
            {
                case 0:
                    printf("Zero\n");
                    break;
                case 1:
                    printf("One\n");
                    break;
                case 2:
                    printf("Two\n");
                    break;
                case 3:
                    printf("Three\n");
                    break;
                case 4:
                    printf("Four\n");
                    break;
                case 5:
                    printf("Five\n");
                    break;
                case 6:
                    printf("Six\n");
                    break;
                case 7:
                    printf("Seven\n");
                    break;
                case 8:
                    printf("Eight\n");
                    break;
                case 9:
                    printf("Nine\n");
                    break;
            }
        }
        printf("Number of digits: %d\n", count);
    }

    return 0;
}