//GPT-4o-mini DATASET v1.0 Category: Audio processing ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <sndfile.h> // Ensuring that you have libsndfile installed
#include <string.h>

// A mystical bard's song processing program
typedef struct {
    double *samples;
    sf_count_t num_samples;
    int sample_rate;
} BardicTune;

BardicTune *create_bardic_tune(const char *filename) {
    // The bard's magical creation of a tune from a file
    BardicTune *tune = (BardicTune *)malloc(sizeof(BardicTune));
    SNDFILE *file;
    SF_INFO sfinfo;

    sfinfo.format = 0;
    file = sf_open(filename, SFM_READ, &sfinfo);
    if (!file) {
        fprintf(stderr, "Error opening file: %s\n", sf_strerror(NULL));
        return NULL;
    }

    tune->num_samples = sfinfo.frames * sfinfo.channels;
    tune->samples = (double *)malloc(tune->num_samples * sizeof(double));
    if (!tune->samples) {
        fprintf(stderr, "Memory allocation failed!\n");
        sf_close(file);
        return NULL;
    }

    // Read the bard's tune into memory
    sf_readf_double(file, tune->samples, sfinfo.frames);
    tune->sample_rate = sfinfo.samplerate;

    sf_close(file);
    return tune;
}

void destroy_bardic_tune(BardicTune *tune) {
    // Free the magical memory
    if (tune) {
        free(tune->samples);
        free(tune);
    }
}

void apply_mystical_reverb(BardicTune *tune) {
    // A reverb spell is cast upon the tune
    int delay_samples = (int)(0.2 * tune->sample_rate); // 200ms delay
    double decay = 0.5;
    double *reverb = (double *)calloc(tune->num_samples, sizeof(double));

    for (sf_count_t i = 0; i < tune->num_samples; i++) {
        reverb[i] = tune->samples[i];
        if (i >= delay_samples) {
            reverb[i] += decay * reverb[i - delay_samples];
        }
        reverb[i] = fmin(reverb[i], 1.0); // Clipping to prevent distortion
    }

    memcpy(tune->samples, reverb, tune->num_samples * sizeof(double));
    free(reverb);
}

void save_bardic_tune(const char *filename, BardicTune *tune) {
    // The bard's reconstructed tune is saved
    SNDFILE *file;
    SF_INFO sfinfo;

    sfinfo.frames = tune->num_samples;
    sfinfo.samplerate = tune->sample_rate;
    sfinfo.channels = 1; // Mono output
    sfinfo.format = SF_FORMAT_WAV | SF_FORMAT_PCM_16;

    file = sf_open(filename, SFM_WRITE, &sfinfo);
    if (!file) {
        fprintf(stderr, "Error opening output file: %s\n", sf_strerror(NULL));
        return;
    }

    sf_writef_double(file, tune->samples, sfinfo.frames);
    sf_close(file);
}

int main(int argc, char *argv[]) {
    // The bard's melodic path through the program's parameters
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <input_file> <output_file>\n", argv[0]);
        return 1;
    }

    const char *input_filename = argv[1];
    const char *output_filename = argv[2];

    BardicTune *tune = create_bardic_tune(input_filename);
    if (!tune) {
        return 1; // Error in creating the tune
    }

    apply_mystical_reverb(tune); // Conjure the reverb over the tune
    save_bardic_tune(output_filename, tune); // Save the bardic creation

    printf("The bard's song has been transformed!\n");
    destroy_bardic_tune(tune); // Release the magic's hold

    return 0;
}