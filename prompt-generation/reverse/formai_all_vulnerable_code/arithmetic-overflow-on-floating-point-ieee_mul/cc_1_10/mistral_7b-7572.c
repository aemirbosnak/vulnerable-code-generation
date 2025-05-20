//MISTRAL-7B DATASET v1.0 Category: Unit converter ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    float value;
    char symbol;
} Unit;

Unit units[] = {
    {3.28084, 'F'},
    {0.0254, 'm'},
    {1.0, 'K'},
    {1.60934, 'M'},
    {1000.0, 'L'},
    {1.21527, 'Gal'},
    {2.20462, 'lb'},
    {1.42857, 'Stone'},
    {0.078125, 'Ton'},
    {25400.0, 'Mile'}
};

void print_usage() {
    printf("Usage:\n");
    printf("cyberpunk_unit_converter <value> <from_unit> <to_unit>\n");
    printf("Example:\n");
    printf("cyberpunk_unit_converter 10 F K\n");
}

int main(int argc, char* argv[]) {
    if (argc != 4) {
        print_usage();
        return 1;
    }

    float value = atof(argv[1]);
    char from_symbol = argv[2][0];
    char to_symbol = argv[3][0];

    for (int i = 0; i < sizeof(units) / sizeof(Unit); i++) {
        if (units[i].symbol == from_symbol) {
            value *= units[i].value;
            break;
        }
    }

    for (int i = 0; i < sizeof(units) / sizeof(Unit); i++) {
        if (units[i].symbol == to_symbol) {
            float result = value / units[i].value;
            printf("%.2f %c = %.2f %c\n", value, from_symbol, result, to_symbol);
            return 0;
        }
    }

    printf("Invalid units.\n");
    print_usage();
    return 1;
}