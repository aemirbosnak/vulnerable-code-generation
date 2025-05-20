//Gemma-7B DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MOD 23

int prime(int n)
{
    if (n <= 1)
        return 0;
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
            return 0;
    }
    return 1;
}

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int main()
{
    char msg[] = "Hello, world!";
    int msg_len = strlen(msg);

    int n, e, d;
    n = prime(512);
    e = gcd(n, 3);
    d = (n - 1) / e;

    int key[n];
    for (int i = 0; i < n; i++)
        key[i] = rand() % MOD;

    int enc_msg[msg_len];
    for (int i = 0; i < msg_len; i++)
        enc_msg[i] = (msg[i] - 'a' + key[i]) % MOD;

    int dec_msg[msg_len];
    for (int i = 0; i < msg_len; i++)
        dec_msg[i] = (enc_msg[i] - key[i]) % MOD + 'a';

    for (int i = 0; i < msg_len; i++)
        printf("%c", dec_msg[i]);

    printf("\n");

    return 0;
}