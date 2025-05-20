//MISTRAL-7B DATASET v1.0 Category: Performance-Critical Component ; Style: scientific
#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include <string.h>
#include <math.h>

// FIR filter coefficients
const float fir_coeffs[10] = {0.03125f, 0.0625f, 0.09375f, 0.125f, 0.15625f, 0.1875f, 0.21875f, 0.25f, 0.28125f, 0.3125f};

// FIR filter state variables
static float fir_state[11] = {0.0f};

// Input buffer and size
static float input_buffer[256] = {0.0f};
static size_t buffer_size = 0;

// Output buffer and size
static float output_buffer[256] = {0.0f};
static size_t output_size = 0;

// Initialize FIR filter
void fir_init(void) {
    memset(fir_state, 0, sizeof(fir_state));
}

// Process an input sample through FIR filter
void fir_process(float sample) {
    // Update FIR filter output and internal state
    output_buffer[output_size] = sample;
    float filter_output = fir_state[0] * fir_coeffs[0];

    for (size_t i = 1; i < 10; ++i) {
        filter_output += fir_state[i] * fir_coeffs[i];
    }

    for (size_t i = 10; i < 11; ++i) {
        float tmp = fir_state[i];
        fir_state[i] = filter_output;
        filter_output = tmp * fir_coeffs[i];
    }

    ++output_size;
}

// Process input buffer through FIR filter
void fir_process_buffer(const float *input, size_t length) {
    buffer_size = length;
    memset(input_buffer, 0, sizeof(input_buffer));
    memset(output_buffer, 0, sizeof(output_buffer));

    for (size_t i = 0; i < length; ++i) {
        input_buffer[i] = input[i];
        fir_process(input[i]);
    }
}

int main(void) {
    // Initialize FIR filter
    fir_init();

    // Input signal data
    const float input_data[] = {1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f, 7.0f, 8.0f, 9.0f, 10.0f};

    // Process input buffer through FIR filter
    fir_process_buffer(input_data, sizeof(input_data) / sizeof(input_data[0]));

    // Output result data
    for (size_t i = 0; i < output_size; ++i) {
        printf("%.6f ", output_buffer[i]);
    }
    printf("\n");

    return 0;
}