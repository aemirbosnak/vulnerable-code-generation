//FormAI DATASET v1.0 Category: Data mining ; Style: calm
/*
Title: C Data Mining Example Program
Description: This program demonstrates data mining by reading in a file and calculating various statistics, such as the mean and standard deviation of the data.
Author: [Your Name]
Date: [Date]

To use this program, simply input the filename of the data file followed by the number of data points.
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_DATA_POINTS 1000 // Maximum number of data points

int main(){
	/* Declarations */
	FILE *fp;
	char filename[100];
	int num_data_points, i;
	float data[MAX_DATA_POINTS], mean, variance, std_dev;
	
	/* User Input */
	printf("Enter filename of data: ");
	scanf("%s", filename);
	
	printf("Enter number of data points: ");
	scanf("%i", &num_data_points);
	
	/* Open Data File */
	fp = fopen(filename, "r");
	if(fp == NULL){
		printf("Error: Cannot open file.\n");
		exit(EXIT_FAILURE);
	}
	
	/* Read Data */
	for(i=0; i<num_data_points; i++){
		if(fscanf(fp, "%f", &data[i]) != 1){
			printf("Error: Data read error.\n");
			exit(EXIT_FAILURE);
		}
	}
	
	/* Calculate Mean */
	mean = 0;
	for(i=0; i<num_data_points; i++){
		mean += data[i];
	}
	mean /= num_data_points;
	
	/* Calculate Variance */
	variance = 0;
	for(i=0; i<num_data_points; i++){
		variance += pow(data[i] - mean, 2);
	}
	variance /= num_data_points;
	
	/* Calculate Standard Deviation */
	std_dev = sqrt(variance);
	
	/* Print Results */
	printf("Mean: %f\n", mean);
	printf("Variance: %f\n", variance);
	printf("Standard Deviation: %f\n", std_dev);

	/* Close File */
	fclose(fp);
	
	return 0;
}