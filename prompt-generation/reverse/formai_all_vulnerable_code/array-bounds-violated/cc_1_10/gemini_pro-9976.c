//GEMINI-pro DATASET v1.0 Category: User Input Sanitizer ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum {
    INPUT_TYPE_INTEGER,
    INPUT_TYPE_FLOAT,
    INPUT_TYPE_STRING,
    INPUT_TYPE_CUSTOM
} input_type_t;

typedef struct {
    input_type_t type;
    union {
        int (*integer_validator)(int);
        float (*float_validator)(float);
        char *(*string_validator)(char *);
        void *(*custom_validator)(void *);
    } validator;
} input_validation_rule_t;

int integer_validator_range(int value) {
    return value >= 0 && value <= 100;
}

float float_validator_range(float value) {
    return value >= -100.0f && value <= 100.0f;
}

char *string_validator_length(char *string) {
    return strlen(string) >= 5 && strlen(string) <= 20 ? string : NULL;
}

void *custom_validator_example(void *value) {
    // Custom validation logic here
    return value;
}

int main() {
    input_validation_rule_t rules[] = {
        {INPUT_TYPE_INTEGER, {.integer_validator = integer_validator_range}},
        {INPUT_TYPE_FLOAT, {.float_validator = float_validator_range}},
        {INPUT_TYPE_STRING, {.string_validator = string_validator_length}},
        {INPUT_TYPE_CUSTOM, {.custom_validator = custom_validator_example}}
    };

    char buffer[1024];
    int rule_index;
    int result;

    printf("Enter the input type (integer, float, string, custom): ");
    fgets(buffer, sizeof(buffer), stdin);
    sscanf(buffer, "%d", &rule_index);

    printf("Enter the input value: ");
    fgets(buffer, sizeof(buffer), stdin);

    switch (rules[rule_index].type) {
    case INPUT_TYPE_INTEGER:
        sscanf(buffer, "%d", &result);
        if (rules[rule_index].validator.integer_validator(result)) {
            printf("Valid integer: %d\n", result);
        } else {
            printf("Invalid integer\n");
        }
        break;
    case INPUT_TYPE_FLOAT:
        sscanf(buffer, "%f", &result);
        if (rules[rule_index].validator.float_validator(result)) {
            printf("Valid float: %f\n", result);
        } else {
            printf("Invalid float\n");
        }
        break;
    case INPUT_TYPE_STRING:
        if (rules[rule_index].validator.string_validator(buffer)) {
            printf("Valid string: %s\n", buffer);
        } else {
            printf("Invalid string\n");
        }
        break;
    case INPUT_TYPE_CUSTOM:
        if (rules[rule_index].validator.custom_validator(buffer)) {
            printf("Valid custom input\n");
        } else {
            printf("Invalid custom input\n");
        }
        break;
    default:
        printf("Invalid input type\n");
        break;
    }

    return 0;
}