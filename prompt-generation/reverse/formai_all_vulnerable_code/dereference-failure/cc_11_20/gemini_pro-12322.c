//GEMINI-pro DATASET v1.0 Category: Scientific Calculator Implementation ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

#define MIN(a,b) ((a)<(b)?(a):(b))
#define POW(x,y) pow(x,y)
#define FE(x) exp(x)
#define LN(x) log(x)
#define SR(x) sqrt(x)
#define TA(x) tan(x)
#define TA(x) tanh(x)
#define SE(x) sin(x)
#define CO(x) cos(x)
#define LO(x) log10(x)
#define SA(x,y) asin(x)/asin(y)

struct CalcArgs {
    char *op;
    int index;
    int op_len;
    int in_error;
};

int calc(char **args, int argc) {
    if (argc < 3) {
        printf("Usage: %s <operator> <arguments>\n", args[0]);
        return 1;
    }

    struct CalcArgs ca = {args[1], 2, strlen(args[1]), 0};
    while (ca.index < argc && !ca.in_error) {
        if (ca.op_len == 1) {
            switch (ca.op[0]) {
            case '+':
                printf("%f\n", atof(args[ca.index]) + atof(args[ca.index+1]));
                ca.index += 2;
                break;
            case '-':
                printf("%f\n", atof(args[ca.index]) - atof(args[ca.index+1]));
                ca.index += 2;
                break;
            case '*':
                printf("%f\n", atof(args[ca.index]) * atof(args[ca.index+1]));
                ca.index += 2;
                break;
            case '/':
                printf("%f\n", atof(args[ca.index]) / atof(args[ca.index+1]));
                ca.index += 2;
                break;
            case '^':
                printf("%f\n", pow(atof(args[ca.index]), atof(args[ca.index+1])));
                ca.index += 2;
                break;
            case 'S':
                if (!strcmp(args[ca.index], "FE")) {
                    printf("%f\n", exp(atof(args[ca.index+1])));
                    ca.index += 2;
                } else if (!strcmp(args[ca.index], "LN")) {
                    printf("%f\n", log(atof(args[ca.index+1])));
                    ca.index += 2;
                } else if (!strcmp(args[ca.index], "SR")) {
                    printf("%f\n", sqrt(atof(args[ca.index+1])));
                    ca.index += 2;
                } else if (!strcmp(args[ca.index], "TA")) {
                    printf("%f\n", tan(atof(args[ca.index+1])));
                    ca.index += 2;
                } else if (!strcmp(args[ca.index], "SA")) {
                    printf("%f\n", asin(atof(args[ca.index+1])) / asin(atof(args[ca.index+2])));
                    ca.index += 3;
                } else {
                    ca.in_error = 1;
                }
                break;
            case 'C':
                if (!strcmp(args[ca.index], "SE")) {
                    printf("%f\n", sin(atof(args[ca.index+1])));
                    ca.index += 2;
                } else if (!strcmp(args[ca.index], "CO")) {
                    printf("%f\n", cos(atof(args[ca.index+1])));
                    ca.index += 2;
                } else if (!strcmp(args[ca.index], "TA")) {
                    printf("%f\n", tanh(atof(args[ca.index+1])));
                    ca.index += 2;
                } else {
                    ca.in_error = 1;
                }
                break;
            case 'L':
                if (!strcmp(args[ca.index], "LN")) {
                    printf("%f\n", logl(atof(args[ca.index+1])));
                    ca.index += 2;
                } else if (!strcmp(args[ca.index], "LO")) {
                    printf("%f\n", log10(atof(args[ca.index+1])));
                    ca.index += 2;
                } else {
                    ca.in_error = 1;
                }
                break;
            default:
                ca.in_error = 1;
                break;
            }
        } else if (ca.op_len == 2 && !strcmp(ca.op, "MIN")) {
            printf("%f\n", MIN(atof(args[ca.index]), atof(args[ca.index+1])));
            ca.index += 2;
        } else {
            ca.in_error = 1;
        }
    }

    if (ca.in_error) {
        printf("Invalid operator: %s\n", args[1]);
        return 1;
    }

    return 0;
}

int main(int argc, char **argv) {
    return calc(argv, argc);
}