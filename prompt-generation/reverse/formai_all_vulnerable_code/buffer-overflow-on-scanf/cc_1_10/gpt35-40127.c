//FormAI DATASET v1.0 Category: Digital signal processing ; Style: surprised
#include<stdio.h>
#include<math.h>

//Function to calculate frequency response of a filter
void freq_response(float b[], float a[], int N, float w[], float Hr[]) {
  int i,j;
  float num, den;

  for(i=0; i<N; i++) {
    num=0; den=0;
    for(j=0; j<=i; j++) {
      num += b[j]*cos(j*w[i]);
      den += a[j]*cos(j*w[i]);
    }
    Hr[i] = num/den;
  }
}

int main() {
  int i,N;
  float wmax,Hmax;
  float b[10], a[10], w[1000], Hr[1000], Hdb[1000];
  
  printf("Enter the order of filter: ");
  scanf("%d",&N);
  
  printf("Enter the maximum frequency: ");
  scanf("%f",&wmax);
  
  printf("Enter the maximum gain in dB: ");
  scanf("%f",&Hmax);

  //Generating the filter coefficients
  for(i=0; i<=N; i++) {
    printf("Enter the value of b[%d]: ",i);
    scanf("%f",&b[i]);
  }
  
  for(i=0; i<=N; i++) {
    printf("Enter the value of a[%d]: ",i);
    scanf("%f",&a[i]);
  }

  //Generating the frequency vector
  for(i=0; i<1000; i++) {
    w[i] = wmax*(float)i/999;
  }

  freq_response(b,a,N,w,Hr);
  
  //Converting the frequency response to dB
  for(i=0; i<1000; i++) {
    Hdb[i] = 20*log10(Hr[i]);
  }
  
  //Printing the frequency response
  printf("Frequency Response:\n");
  for(i=0; i<1000; i++) {
    printf("%f %f\n",w[i],Hdb[i]);
    if(Hdb[i]>Hmax) {
      printf("Filter exceeds maximum gain at %f Hz\n",w[i]);
    }
  }
  
  return 0;
}