//FormAI DATASET v1.0 Category: File handling ; Style: statistical
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(){
    FILE *fp;
    int i,n;
    float sum=0.0,mean=0.0,variance=0.0,sd=0.0;
    float *data;

    fp=fopen("data.txt","w+"); //opening a file for writing the data
    if(fp==NULL){
        printf("Error in opening file\n");
        exit(0);
    }

    printf("Enter the number of data points:\n");
    scanf("%d",&n);

    data=(float*)malloc(sizeof(float)*n); //allocating memory dynamically

    printf("Enter the data points:\n");
    for(i=0;i<n;i++){
        scanf("%f",&data[i]);
        fprintf(fp,"%f\n",data[i]); //writing data to the file
    }

    fclose(fp); //closing the file

    fp=fopen("data.txt","r"); //opening the file for reading the data
    if(fp==NULL){
        printf("Error in opening file\n");
        exit(0);
    }

    printf("The data points are:\n");
    for(i=0;i<n;i++){
        fscanf(fp,"%f",&data[i]); //reading data from the file
        printf("%f\n",data[i]);
        sum+=data[i]; //finding the sum of data points
    }

    mean=sum/n; //finding the mean of data points

    fclose(fp); //closing the file

    fp=fopen("result.txt","w+"); //opening a file for writing the results
    if(fp==NULL){
        printf("Error in opening file\n");
        exit(0);
    }

    fprintf(fp,"The data points are:\n");
    for(i=0;i<n;i++)
        fprintf(fp,"%f\n",data[i]); //writing data to the file

    fprintf(fp,"The mean of data is: %f\n",mean); //writing mean to the file

    for(i=0;i<n;i++)
        variance+=(data[i]-mean)*(data[i]-mean); //finding the variance of data points

    variance/=n; //dividing variance by number of data points

    sd=sqrt(variance); //finding the standard deviation of data points

    fprintf(fp,"The variance of data is: %f\n",variance); //writing variance to the file
    fprintf(fp,"The standard deviation of data is: %f\n",sd); //writing standard deviation to the file

    fclose(fp); //closing the file

    free(data); //freeing the allocated memory

    return 0;
}