//Gemma-7B DATASET v1.0 Category: Unit converter ; Style: invasive
#include <stdio.h>
#include <stdlib.h>

void inv_unit_converter(int argc, char *argv[])
{
    char unit_from, unit_to;
    double value;

    if (argc != 4)
    {
        printf("Usage: inv_unit_converter <value> <unit_from> <unit_to>\n");
        exit(1);
    }

    unit_from = argv[2][0];
    unit_to = argv[3][0];

    switch (unit_from)
    {
        case 'm':
            switch (unit_to)
            {
                case 'kg':
                    value *= 1000;
                    break;
                case 'g':
                    value *= 1000000;
                    break;
                case 't':
                    value *= 1000000000;
                    break;
            }
            break;
        case 'kg':
            switch (unit_to)
            {
                case 'm':
                    value /= 1000;
                    break;
                case 'g':
                    value *= 1000;
                    break;
                case 't':
                    value *= 1000000;
                    break;
            }
            break;
        case 'g':
            switch (unit_to)
            {
                case 'm':
                    value /= 1000000;
                    break;
                case 'kg':
                    value /= 1000;
                    break;
                case 't':
                    value *= 1000000;
                    break;
            }
            break;
        case 't':
            switch (unit_to)
            {
                case 'm':
                    value /= 1000000000;
                    break;
                case 'kg':
                    value /= 1000000;
                    break;
                case 'g':
                    value *= 1000000;
                    break;
            }
            break;
    }

    printf("%f %s is equal to %f %s\n", value, unit_from, value, unit_to);
}

int main(int argc, char *argv[])
{
    inv_unit_converter(argc, argv);

    return 0;
}