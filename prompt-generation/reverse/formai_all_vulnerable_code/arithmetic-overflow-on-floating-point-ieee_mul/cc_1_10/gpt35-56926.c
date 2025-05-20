//FormAI DATASET v1.0 Category: Temperature Converter ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct conversion_input {
    char from_scale;
    char to_scale;
    double temperature;
} ConversionInput;

typedef struct conversion_output {
    bool success;
    double temperature;
    char* message;
} ConversionOutput;

ConversionOutput convert_temperature(ConversionInput input) {
    ConversionOutput output;
    output.success = true;
    output.temperature = input.temperature;
    output.message = NULL;

    if (input.from_scale == 'F' && input.to_scale == 'C') {
        output.temperature = (input.temperature - 32) * (5.0 / 9.0);
    } else if (input.from_scale == 'C' && input.to_scale == 'F') {
        output.temperature = (input.temperature * (9.0 / 5.0)) + 32;
    } else if (input.from_scale == input.to_scale) {
        output.message = strdup("No conversion needed!");
    } else {
        output.success = false;
        output.message = strdup("Unsupported temperature conversion!");
    }

    return output;
}

typedef struct async_state {
    ConversionInput input;
    ConversionOutput output;
    bool is_complete;
} AsyncState;

void async_convert_temperature(AsyncState* state) {
    state->output = convert_temperature(state->input);
    state->is_complete = true;
}

int main() {
    char scale_from, scale_to;
    double temperature;

    printf("Enter temperature: ");
    scanf("%lf", &temperature);

    printf("Enter scale from (C/F): ");
    scanf(" %c", &scale_from);

    printf("Enter scale to (C/F): ");
    scanf(" %c", &scale_to);

    ConversionInput input = { scale_from, scale_to, temperature };
    ConversionOutput output = convert_temperature(input);

    if (output.success) {
        printf("Converted temperature: %.2f %c\n", output.temperature, scale_to);
    } else {
        printf("Conversion failed: %s\n", output.message);
    }

    AsyncState state = { input, { false }, false };
    async_convert_temperature(&state);

    while (!state.is_complete) {}

    ConversionOutput async_output = state.output;

    if (async_output.success) {
        printf("Async converted temperature: %.2f %c\n", async_output.temperature, scale_to);
    } else {
        printf("Async conversion failed: %s\n", async_output.message);
    }

    free(async_output.message);

    return 0;
}