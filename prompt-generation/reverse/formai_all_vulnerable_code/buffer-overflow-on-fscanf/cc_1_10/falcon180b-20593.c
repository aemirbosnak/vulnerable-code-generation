//Falcon-180B DATASET v1.0 Category: Audio processing ; Style: light-weight
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define SAMPLE_RATE 44100
#define PI 3.14159265358979323846

typedef struct{
    int note;
    int velocity;
    int start_time;
    int end_time;
}note_t;

int main(){
    int i, j, n_notes;
    double sample_time, frequency, amplitude;
    double **signal;
    FILE *input_file, *output_file;
    note_t *notes;

    //Read input file
    input_file = fopen("input.txt", "r");
    fscanf(input_file, "%d", &n_notes);
    notes = (note_t*)malloc(n_notes*sizeof(note_t));
    for(i=0; i<n_notes; i++){
        fscanf(input_file, "%d %d %d %d", &notes[i].note, &notes[i].velocity, &notes[i].start_time, &notes[i].end_time);
    }
    fclose(input_file);

    //Allocate memory for signal
    signal = (double**)malloc(n_notes*sizeof(double*));
    for(i=0; i<n_notes; i++){
        signal[i] = (double*)malloc(SAMPLE_RATE*sizeof(double));
    }

    //Generate signal
    for(i=0; i<n_notes; i++){
        frequency = notes[i].note*440.0/12.0;
        amplitude = notes[i].velocity/127.0;
        for(j=0; j<SAMPLE_RATE; j++){
            sample_time = j*1.0/SAMPLE_RATE;
            if(sample_time>=notes[i].start_time && sample_time<=notes[i].end_time){
                signal[i][j] = amplitude*sin(2*PI*frequency*sample_time);
            }else{
                signal[i][j] = 0.0;
            }
        }
    }

    //Write output file
    output_file = fopen("output.txt", "w");
    for(i=0; i<n_notes; i++){
        fprintf(output_file, "%d ", notes[i].note);
        for(j=0; j<SAMPLE_RATE; j++){
            fprintf(output_file, "%lf ", signal[i][j]);
        }
        fprintf(output_file, "\n");
    }
    fclose(output_file);

    //Free memory
    for(i=0; i<n_notes; i++){
        free(signal[i]);
    }
    free(signal);
    free(notes);

    return 0;
}