//FormAI DATASET v1.0 Category: Image Classification system ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define INPUT_SIZE 784  // input size of the image (28x28)
#define HIDDEN_SIZE 200 // hidden layer size
#define OUTPUT_SIZE 10  // output size for the classification (0 to 9)

// sigmoid function for activation
double sigmoid(double x){
    return 1 / (1 + exp(-x));
}

// derivative of sigmoid function
double sigmoid_derivative(double x){
    return sigmoid(x) * (1 - sigmoid(x));
}

// main function for training the network
int main(){

    // generate random weights between -1 to 1 for input to hidden layer
    double *input_hidden_weights = (double *) malloc(INPUT_SIZE * HIDDEN_SIZE * sizeof(double));
    for(int i = 0; i < INPUT_SIZE * HIDDEN_SIZE; i++){
        input_hidden_weights[i] = -1 + ((double) rand() / (RAND_MAX)) * 2;
    }

    // generate random weights between -1 to 1 for hidden to output layer
    double *hidden_output_weights = (double *) malloc(HIDDEN_SIZE * OUTPUT_SIZE * sizeof(double));
    for(int i = 0; i < HIDDEN_SIZE * OUTPUT_SIZE; i++){
        hidden_output_weights[i] = -1 + ((double) rand() / (RAND_MAX)) * 2;
    }

    // load the training data
    FILE *fp = fopen("train-images.idx3-ubyte", "r");
    fseek(fp, 16, SEEK_SET);
    int num_images = 60000;
    double *input_data = (double *) malloc(num_images * INPUT_SIZE * sizeof(double));
    unsigned char buffer[INPUT_SIZE];
    for(int i = 0; i < num_images * INPUT_SIZE; i++){
        fread(buffer, sizeof(unsigned char), INPUT_SIZE, fp);
        input_data[i] = (double) buffer[i % INPUT_SIZE] / 255.0;
    }
    fclose(fp);

    // load the corresponding labels
    fp = fopen("train-labels.idx1-ubyte", "r");
    fseek(fp, 8, SEEK_SET);
    double *output_data = (double *) malloc(num_images * OUTPUT_SIZE * sizeof(double));
    unsigned char label_buffer;
    for(int i = 0; i < num_images; i++){
        fread(&label_buffer, sizeof(unsigned char), 1, fp);
        for(int j = 0; j < OUTPUT_SIZE; j++){
            output_data[i * OUTPUT_SIZE + j] = 0;
        }
        output_data[i * OUTPUT_SIZE + label_buffer] = 1;
    }
    fclose(fp);

    // train the network
    int batch_size = 100;
    int num_batches = num_images / batch_size;
    double learning_rate = 0.1;
    int num_epochs = 10;
    for(int epoch = 0; epoch < num_epochs; epoch++){
        for(int batch = 0; batch < num_batches; batch++){

            // initialize gradients for the weights
            double *input_hidden_gradients = (double *) calloc(INPUT_SIZE * HIDDEN_SIZE, sizeof(double));
            double *hidden_output_gradients = (double *) calloc(HIDDEN_SIZE * OUTPUT_SIZE, sizeof(double));

            for(int i = 0; i < batch_size; i++){
                int index = batch * batch_size + i;

                // forward pass
                double *input_layer = &input_data[index * INPUT_SIZE];
                double *hidden_layer = (double *) calloc(HIDDEN_SIZE, sizeof(double));
                double *output_layer = (double *) calloc(OUTPUT_SIZE, sizeof(double));
                for(int j = 0; j < HIDDEN_SIZE; j++){
                    double sum = 0;
                    for(int k = 0; k < INPUT_SIZE; k++){
                        sum += input_layer[k] * input_hidden_weights[j * INPUT_SIZE + k];
                    }
                    hidden_layer[j] = sigmoid(sum);
                }
                for(int j = 0; j < OUTPUT_SIZE; j++){
                    double sum = 0;
                    for(int k = 0; k < HIDDEN_SIZE; k++){
                        sum += hidden_layer[k] * hidden_output_weights[j * HIDDEN_SIZE + k];
                    }
                    output_layer[j] = sigmoid(sum);
                }

                // backward pass
                double *target_output = &output_data[index * OUTPUT_SIZE];
                double *output_error = (double *) calloc(OUTPUT_SIZE, sizeof(double));
                for(int j = 0; j < OUTPUT_SIZE; j++){
                    output_error[j] = (output_layer[j] - target_output[j]) * sigmoid_derivative(output_layer[j]);
                }
                double *hidden_error = (double *) calloc(HIDDEN_SIZE, sizeof(double));
                for(int j = 0; j < HIDDEN_SIZE; j++){
                    double sum = 0;
                    for(int k = 0; k < OUTPUT_SIZE; k++){
                        sum += output_error[k] * hidden_output_weights[k * HIDDEN_SIZE + j];
                    }
                    hidden_error[j] = sum * sigmoid_derivative(hidden_layer[j]);
                }

                // calculate gradients
                for(int j = 0; j < HIDDEN_SIZE; j++){
                    for(int k = 0; k < INPUT_SIZE; k++){
                        input_hidden_gradients[j * INPUT_SIZE + k] += hidden_error[j] * input_layer[k];
                    }
                }
                for(int j = 0; j < OUTPUT_SIZE; j++){
                    for(int k = 0; k < HIDDEN_SIZE; k++){
                        hidden_output_gradients[j * HIDDEN_SIZE + k] += output_error[j] * hidden_layer[k];
                    }
                }

                free(hidden_layer);
                free(output_layer);
                free(output_error);
                free(hidden_error);

            }

            // update the weights with gradients
            for(int i = 0; i < HIDDEN_SIZE * INPUT_SIZE; i++){
                input_hidden_weights[i] -= learning_rate * input_hidden_gradients[i] / batch_size;
            }
            for(int i = 0; i < HIDDEN_SIZE * OUTPUT_SIZE; i++){
                hidden_output_weights[i] -= learning_rate * hidden_output_gradients[i] / batch_size;
            }

            // free the gradient memory
            free(input_hidden_gradients);
            free(hidden_output_gradients);

        }

        // evaluate the network on validation set
        fp = fopen("t10k-images.idx3-ubyte", "r");
        fseek(fp, 16, SEEK_SET);
        int num_val_images = 10000;
        double *val_input_data = (double *) malloc(num_val_images * INPUT_SIZE * sizeof(double));
        for(int i = 0; i < num_val_images * INPUT_SIZE; i++){
            fread(buffer, sizeof(unsigned char), INPUT_SIZE, fp);
            val_input_data[i] = (double) buffer[i % INPUT_SIZE] / 255.0;
        }
        fclose(fp);

        fp = fopen("t10k-labels.idx1-ubyte", "r");
        fseek(fp, 8, SEEK_SET);
        double *val_output_data = (double *) malloc(num_val_images * OUTPUT_SIZE * sizeof(double));
        for(int i = 0; i < num_val_images; i++){
            fread(&label_buffer, sizeof(unsigned char), 1, fp);
            for(int j = 0; j < OUTPUT_SIZE; j++){
                val_output_data[i * OUTPUT_SIZE + j] = 0;
            }
            val_output_data[i * OUTPUT_SIZE + label_buffer] = 1;
        }
        fclose(fp);

        int correct = 0;
        for(int i = 0; i < num_val_images; i++){

            // forward pass
            double *input_layer = &val_input_data[i * INPUT_SIZE];
            double *hidden_layer = (double *) calloc(HIDDEN_SIZE, sizeof(double));
            double *output_layer = (double *) calloc(OUTPUT_SIZE, sizeof(double));
            for(int j = 0; j < HIDDEN_SIZE; j++){
                double sum = 0;
                for(int k = 0; k < INPUT_SIZE; k++){
                    sum += input_layer[k] * input_hidden_weights[j * INPUT_SIZE + k];
                }
                hidden_layer[j] = sigmoid(sum);
            }
            for(int j = 0; j < OUTPUT_SIZE; j++){
                double sum = 0;
                for(int k = 0; k < HIDDEN_SIZE; k++){
                    sum += hidden_layer[k] * hidden_output_weights[j * HIDDEN_SIZE + k];
                }
                output_layer[j] = sigmoid(sum);
            }

            int prediction = 0;
            double max_score = output_layer[0];
            for(int j = 1; j < OUTPUT_SIZE; j++){
                if(output_layer[j] > max_score){
                    max_score = output_layer[j];
                    prediction = j;
                }
            }

            if(val_output_data[i * OUTPUT_SIZE + prediction] == 1){
                correct++;
            }

            free(hidden_layer);
            free(output_layer);

        }

        printf("Epoch: %d, Validation Accuracy: %.2f %%\n", epoch + 1, (double) correct / num_val_images * 100);

        free(val_input_data);
        free(val_output_data);

    }

    free(input_hidden_weights);
    free(hidden_output_weights);
    free(input_data);
    free(output_data);

    return 0;

}