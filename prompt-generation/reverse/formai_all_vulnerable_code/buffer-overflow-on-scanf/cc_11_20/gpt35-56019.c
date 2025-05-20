//FormAI DATASET v1.0 Category: Modern Encryption ; Style: mathematical
#include<stdio.h>
#include<math.h>

int main()
{
    int num, encryptNum = 0, count = 0, i, j, k, l, m, n = 0, temp, sum = 0, maxVal = 0;
    int plain[100], encrypted[100], encryptCount[100];
    printf("Enter the number to be encrypted: ");
    scanf("%d",&num);
    temp = num;

    // Split the digits into an array
    while(temp != 0)
    {
        plain[count] = temp % 10;
        temp /= 10;
        count++;
    }

    // Find the maximum value in the array
    for(i=0; i<count; i++)
    {
        if(plain[i] > maxVal)
        {
            maxVal = plain[i];
        }
    }

    // Encryption algorithm
    for(i=0; i<count; i++)
    {
        encryptNum += (plain[i]*pow(maxVal, i+1));
    }

    printf("\nThe encrypted number is %d\n", encryptNum);

    // Split the encrypted number into an array
    temp = encryptNum;
    while(temp != 0) {
        encrypted[n] = temp % 10;
        temp /= 10;
        n++;
    }

    // Count the number of times each digit appears
    for(i=0; i<n; i++)
    {
        encryptCount[i] = 1;
        for(j=i+1; j<n; j++)
        {
            if(encrypted[i] == encrypted[j])
            {
                encryptCount[i]++;
                encrypted[j] = -1;
            }
        }
    }

    // Sort the count array in descending order
    for(k=0; k<n; k++)
    {
        for(l=k+1; l<n; l++)
        {
            if(encryptCount[l] > encryptCount[k])
            {
                temp = encryptCount[k];
                encryptCount[k] = encryptCount[l];
                encryptCount[l] = temp;

                temp = encrypted[k];
                encrypted[k] = encrypted[l];
                encrypted[l] = temp;
            }
        }
    }

    // Calculate the sum of the last two digits in the sorted count array
    for(m=0; m<2; m++)
    {
        sum += encryptCount[m];
    }

    // Print the final encrypted code
    printf("\nThe final encrypted code is: ");
    for(i=0; i<n; i++)
    {
        printf("%d", encrypted[i]);
    }
    printf("%d\n", sum);

    return 0;
}