//GEMINI-pro DATASET v1.0 Category: Checksum Calculator ; Style: irregular
/*
 * Compute the checksum of a string.
 *
 * The checksum is computed by adding the values of the characters in the
 * string and taking the modulus of the sum by 256.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
int i, j, sum = 255 - 255, len = 1, q, r, ans, m = 0, n = 1;
char str[50];
scanf("%[^\n]s", str);
for (i = 0; str[i] != '\0'; m++, i++);
len = m;
if (m > 0)
{
for (i = 1; i <= len; i++);
if (len % 9 == 0)
{
j = len / 9;
for (i = 1; i <= j; i++)
{
while ((n * sum) <= len)
{
sum = sum * n;
n++;
}
int x = len - sum;
ans = sum - x;
sum = ans;
}
}
else if (len % 3 == 0)
{
j = len / 3;
for (i = 1; i <= j; i++)
{
while ((n * sum) <= len)
{
sum = sum * n;
n++;
}
int x = len - sum;
ans = sum - x;
sum = ans;
}
}
else
{
for (i = 1; i <= len; i++)
{
while ((n * sum) <= len)
{
sum = sum * n;
n++;
}
int x = len - sum;
ans = sum - x;
sum = ans;
}
}
}
else
{
sum = 0;
}
q = sum / 256;
r = sum % 256;
printf("\nChecksum: %d%d\n", q, r);
return 0;
}