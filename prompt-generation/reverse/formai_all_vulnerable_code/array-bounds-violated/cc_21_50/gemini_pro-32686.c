//GEMINI-pro DATASET v1.0 Category: Tower of Hanoi Problem ; Style: surprised
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, k = 0;
    printf("Enter the number of disks: ");
    scanf("%d", &n);
    int A[n], B[n], C[n];
    for (int i = 0; i < n; i++)
    {
        A[i] = 0;
        B[i] = 0;
        C[i] = 0;
    }
    A[n - 1] = n;
    while (C[n - 1] != n)
    {
        if (k % 3 == 0)
        {
            for (int i = 0; i < n; i++)
            {
                if (A[i] > 0)
                {
                    for (int j = 0; j < n; j++)
                    {
                        if (B[j] == 0)
                        {
                            B[j] = A[i];
                            A[i] = 0;
                            printf("Move disk %d from A to B\n", B[j]);
                            k++;
                            break;
                        }
                    }
                }
            }
        }
        else if (k % 3 == 1)
        {
            for (int i = 0; i < n; i++)
            {
                if (A[i] > 0)
                {
                    for (int j = 0; j < n; j++)
                    {
                        if (C[j] == 0)
                        {
                            C[j] = A[i];
                            A[i] = 0;
                            printf("Move disk %d from A to C\n", C[j]);
                            k++;
                            break;
                        }
                    }
                }
                else if (B[i] > 0)
                {
                    for (int j = 0; j < n; j++)
                    {
                        if (C[j] == 0)
                        {
                            C[j] = B[i];
                            B[i] = 0;
                            printf("Move disk %d from B to C\n", C[j]);
                            k++;
                            break;
                        }
                    }
                }
            }
        }
        else
        {
            for (int i = 0; i < n; i++)
            {
                if (B[i] > 0)
                {
                    for (int j = 0; j < n; j++)
                    {
                        if (A[j] == 0)
                        {
                            A[j] = B[i];
                            B[i] = 0;
                            printf("Move disk %d from B to A\n", A[j]);
                            k++;
                            break;
                        }
                    }
                }
                else if (C[i] > 0)
                {
                    for (int j = 0; j < n; j++)
                    {
                        if (A[j] == 0)
                        {
                            A[j] = C[i];
                            C[i] = 0;
                            printf("Move disk %d from C to A\n", A[j]);
                            k++;
                            break;
                        }
                    }
                }
            }
        }
    }
    printf("The total number of moves is %d\n", k);
    return 0;
}