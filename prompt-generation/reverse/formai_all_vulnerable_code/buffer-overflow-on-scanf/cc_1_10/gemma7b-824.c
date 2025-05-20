//Gemma-7B DATASET v1.0 Category: Game ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>

int main()
{
    char *p, *q, *r, *s;
    long l, m, n, o, pqr, xyz;

    printf("Enter the number of suspects: ");
    scanf("%ld", &n);

    p = malloc(n * sizeof(char *));
    q = malloc(n * sizeof(char *));
    r = malloc(n * sizeof(char *));
    s = malloc(n * sizeof(char *));

    printf("Enter the suspects' names: ");
    for (l = 0; l < n; l++)
    {
        p[l] = malloc(20 * sizeof(char));
        scanf("%s", p[l]);
    }

    printf("Enter the suspects' occupations: ");
    for (l = 0; l < n; l++)
    {
        q[l] = malloc(20 * sizeof(char));
        scanf("%s", q[l]);
    }

    printf("Enter the suspects' relationships: ");
    for (l = 0; l < n; l++)
    {
        r[l] = malloc(20 * sizeof(char));
        scanf("%s", r[l]);
    }

    printf("Enter the suspects' secrets: ");
    for (l = 0; l < n; l++)
    {
        s[l] = malloc(20 * sizeof(char));
        scanf("%s", s[l]);
    }

    printf("Preparing to interrogate...\n");

    for (l = 0; l < n; l++)
    {
        printf("Suspect #%ld: ", l + 1);
        printf("%s, %s, %s, %s\n", p[l], q[l], r[l], s[l]);
    }

    free(p);
    free(q);
    free(r);
    free(s);

    return 0;
}